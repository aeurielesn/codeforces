/*
* STATUS = ACCEPTED
*/

#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

#define FOR(i,n)   for(int i=0; i<n; ++i)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define SZ(c)      ((int)c.size())

pair<int,int> solve(string sequence)
{
    int state = 0;
    set<int> cuts;

    cuts.insert(-1); cuts.insert(SZ(sequence));

    FOR(i,SZ(sequence))
    {
        if(sequence[i]=='(')
            ++state;
        else if(sequence[i]==')')
            --state;
        if(state < 0)
        {
            cuts.insert(i);
            state = 0;
        }
    }

    state = 0;
    for(int i=SZ(sequence)-1; i>=0; --i)
    {
        if(sequence[i]=='(') --state;
        if(sequence[i]==')') ++state;
        if(state < 0)
        {
            cuts.insert(i);
            state = 0;
        }
    }

    int max_length = 0, cnt = 1, last = -1;
    FORE(it,cuts)
    {
        int d = *it - last - 1;
        if(d > max_length)
        {
            max_length = d;
            cnt = 1;
        }
        else if(d && (d == max_length))
        {
            ++cnt;
        }
        last = *it;
    }

    return make_pair(max_length, cnt);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("longest-regular-bracket-sequence.in","r",stdin);
    #endif

    string sequence;
    getline(cin,sequence);

    pair<int,int> ans = solve(sequence);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}
