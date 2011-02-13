/*
* STATUS = ACCEPTED
*/

#include <cstdio>
#include <vector>
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
        freopen("alice-bob-and-chocolate.in","r",stdin);
    #endif

    int n, time;

    scanf("%d", &n);

    vector<int> chocolates(n + 2, 0);

    FORI(i, 1, n+1)
    {
        scanf("%d", &time);
        chocolates[i] = chocolates[i-1] + time;
    }
    chocolates[n+1] = chocolates[n];


    int left = 0, right = n + 1;

    while(right > left)
    {
        int alice = chocolates[left], bob = chocolates[n+1] - chocolates[right];
        if((alice < bob) || (alice == bob))
        {
            left++;
        }
        else if(bob < alice)
        {
            right--;
        }
    }

    printf("%d %d\n", left, n - left);

    return 0;
}
