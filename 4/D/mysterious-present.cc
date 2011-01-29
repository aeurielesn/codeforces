/*
* STATUS = ACCEPTED
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

#define MAX 5001

int w[MAX], h[MAX], s[MAX], cnt[MAX], path[MAX];

bool cmp(const int a, const int b)
{
    if(w[a] == w[b]) return h[a] > h[b];
    return w[a] > w[b];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("mysterious-present.in","r",stdin);
    #endif

    int n, W, H;

    scanf("%d%d%d",&n,&W,&H);

    for(int i=0; i<n; ++i)
    {
        cnt[i] = 1; path[i] = -1; s[i] = i;
        scanf("%d%d",&w[i],&h[i]);
    }

    sort(s,s+n,cmp);

    for(int i=1; i<n; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            if(h[s[i]] < h[s[j]] && w[s[i]] < w[s[j]])
            {
                if(cnt[j] + 1 > cnt[i])
                {
                    cnt[i] = cnt[j] + 1;
                    path[i] = j;
                }
            }
        }
    }

    int answer = 0, best = -1;
    for(int i=0; i<n; ++i)
    {
        if(H < h[s[i]] && W < w[s[i]])
        {
            if(cnt[i] > answer)
            {
                best = i;
                answer = cnt[i];
            }
        }
    }

    printf("%d\n",answer);
    if(best != -1)
    {
        bool y = false;
        while(best != -1)
        {
            if(y) printf(" ");
            printf("%d",s[best]+1);
            best = path[best];
            y = true;
        }
        printf("\n");
    }

    return 0;
}
