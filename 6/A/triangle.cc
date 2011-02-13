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
#define FORI(i,a,n)   for(int i=a; i<n; ++i)
#define SZ(c)      ((int)c.size())

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("triangle.in","r",stdin);
    #endif

    int sides[4];
    bool triangle = false, segment = false;

    FOR(i,4) scanf("%d", &sides[i]);

    FOR(i,4)
    {
        FORI(j, i+1, 4)
        {
            int low_bound = abs(sides[i] - sides[j]);
            int upper_bound = sides[i] + sides[j];
            FORI(k, j+1, 4)
            {
                if(sides[k] == low_bound || sides[k] == upper_bound)
                    segment |= true;
                else if(sides[k] > low_bound && sides[k] < upper_bound)
                    triangle |= true;
            }
        }
    }

    if(triangle)
        printf("TRIANGLE\n");
    else if(segment)
        printf("SEGMENT\n");
    else
        printf("IMPOSSIBLE\n");

    return 0;
}
