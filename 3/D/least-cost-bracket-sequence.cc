/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define SZ(c) ((int)c.size())

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("least-cost-bracket-sequence.in","r",stdin);
    #endif

    int m = 0;
    string pattern, str;

    getline(cin, pattern);
    m = count(pattern.begin(), pattern.end(), '?');

    vector< pair<int,int> > jokers(m);

    FOR(i,m)
    {
        getline(cin,str);
        sscanf(str.c_str(),"%d%d",&jokers[i].first,&jokers[i].second);
    }

    vector<bool> is_joker(SZ(pattern),false);

    long long sum = 0;
    for(int i=0,j=0;i<SZ(pattern);++i)
    {
        if(pattern[i]=='?')
        {
            is_joker[i] = true;
            pattern[i] = ')';
            sum += jokers[j++].second;
        }
    }

    // Greedy as suggested on multiple codeforces blog entries
    int st = 0;
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > Q;
    for(int i=0,k=0;i<SZ(pattern);++i)
    {
        if(is_joker[i])
        {
            Q.push(make_pair(jokers[k].first-jokers[k].second, i));
            k++;
        }
        if(pattern[i]=='(') ++st;
        else if(pattern[i]==')') --st;
        if(st < 0)
        {
            if(!Q.empty())
            {
                pair<int,int> j = Q.top(); Q.pop();
                sum += j.first;
                pattern[j.second] = '(';
                st += 2;
            }
            else
            {
                break;
            }
        }
    }

    if(st)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << sum << endl << pattern << endl;
    }


    return 0;
}
