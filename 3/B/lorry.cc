/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define SZ(c) ((int)c.size())

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("lorry.in","r",stdin);
    #endif

    int n, v, maxi = 0, bk = 0, bc = 0;
    vector< pair<int,int> > kayak, catamaran;

    scanf("%d%d",&n,&v);

    FOR(i, n)
    {
        int t, p;
        scanf("%d%d",&t,&p);
        if(t==1) kayak.push_back( make_pair(p, i+1) );
        else if(t==2) catamaran.push_back( make_pair(p, i+1) );
    }

    sort(kayak.rbegin(), kayak.rend());
    sort(catamaran.rbegin(), catamaran.rend());

    int k = 0, c = 0, sum = 0;

    k = min(SZ(kayak), v);
    FOR(i,k) sum += kayak[i].first;

    c = min(SZ(catamaran), (v - k)/2);
    FOR(i,c) sum += catamaran[i].first;

    if(sum > maxi) maxi = sum, bk = k, bc = c;

    while(k && c < SZ(catamaran))
    {
        sum -= kayak[--k].first;
        if(k + (c + 1) * 2 <= v)
        {
            sum += catamaran[c++].first;
        }
        if(sum > maxi)
        {
            maxi = sum, bk = k, bc = c;
        }
    }

    printf("%d\n", maxi);
    FOR(i,bk) printf("%d\n", kayak[i].second);
    FOR(i,bc) printf("%d\n", catamaran[i].second);

    return 0;
}
