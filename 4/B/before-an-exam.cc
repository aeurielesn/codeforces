/*
* STATUS = ACCEPTED
*/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int d, sum_time, lower_bound = 0, upper_bound = 0;

    scanf("%d%d",&d,&sum_time);

    vector< pair<int,int> > times(d);
    for(int i=0,min_time,max_time; i<d; ++i)
    {
        scanf("%d%d",&min_time,&max_time);
        times[i] = make_pair(min_time, max_time);
        lower_bound += min_time;
        upper_bound += max_time;
    }

    if(lower_bound <= sum_time && sum_time <= upper_bound)
    {
        printf("YES\n");
        int r = sum_time - lower_bound;
        for(int i=0; i<d; ++i)
        {
            int j = min(times[i].second - times[i].first, r);
            if(i) printf(" ");
            printf("%d", times[i].first + j);
            r -= j;
        }
        printf("\n");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
