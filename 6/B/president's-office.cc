/*
* STATUS = ACCEPTED
*/

#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

#define FOR(i,n)   for(int i=0; i<n; ++i)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define SZ(c)      ((int)c.size())

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("president's-office.in","r",stdin);
    #endif

    int n, m;
    string str, c;
    int dir[][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
    set<char> deputies;

    getline(cin, str);
    istringstream strin(str);
    strin >> n >> m >> c;

    vector<string> room(n);

    FOR(i,n)
    {
        getline(cin, room[i]);
    }


    FOR(i,n)
    {
        FOR(j,m)
        {
            if(room[i][j] == c[0])
            {
                FOR(k, 4)
                {
                    int ii = i + dir[k][0], jj = j + dir[k][1];
                    if((ii >= 0) && (ii < n) && (jj >= 0) && (jj < m))
                    {
                        if(room[ii][jj] != c[0] && room[ii][jj] != '.')
                        {
                            deputies.insert(room[ii][jj]);
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", deputies.size());

    return 0;
}
