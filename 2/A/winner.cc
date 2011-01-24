#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORE(it,c) for(__typeof__(c.begin()) it=c.begin(); it!=c.end(); it++)

using namespace std;

int main()
{
    int N, M = -1000001;
    string who;
    map<string,int> scores, winners;

    cin >> N;

    vector< pair<string,int> > rounds(N);

    FOR(i,N)
    {
        cin >> rounds[i].first >> rounds[i].second;
        map<string,int>::iterator it = scores.find(rounds[i].first);
        if(it == scores.end()) scores[rounds[i].first] = 0;
        scores[rounds[i].first] += rounds[i].second;
    }

    FORE(it,scores)
    {
        M = max(M, it->second);
    }

    FORE(it,scores)
    {
        if(it->second == M)
        {
            winners[it->first] = 0;
        }
    }

    FOR(i,N)
    {
        if(winners.find(rounds[i].first) == winners.end()) continue;
        winners[rounds[i].first] += rounds[i].second;
        if(winners[rounds[i].first] >= M)
        {
            who = rounds[i].first;
            break;
        }
    }

    cout << who << endl;

    return 0;
}
