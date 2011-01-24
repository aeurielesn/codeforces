/*
* STATUS: MEMORY LIMIT EXCEEDED
*/

#include <iostream>
#include <cstdio>
#include <vector>

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORE(it,c) for(__typeof__(c.begin()) it=c.begin(); it!=c.end(); it++)

using namespace std;

#define MAX 100000

int power(long long number, long long base)
{
    int p = 0;
    while(number%base==0LL)
        number /= base,
        p++;
    return p;
}

int main()
{
    bool zero = false;
    int n;
    long long k;

    scanf("%d", &n);

    vector< vector< pair<int,int> > > matrix(n, vector< pair<int,int> >(n));
    vector< vector< pair<int,string> > > m2(n, vector< pair<int,string> >(n, pair<int,string>(MAX,"")));
    vector< vector< pair<int,string> > > m5(n, vector< pair<int,string> >(n, pair<int,string>(MAX,"")));

    FOR(i, n)
    {
        FOR(j, n)
        {
            scanf("%I64d", &k);
            if(k==0LL) zero = true, k = 10LL;
            matrix[i][j] = make_pair(power(k, 2LL), power(k, 5LL));
        }
    }

    m2[0][0].first = matrix[0][0].first, m5[0][0].first = matrix[0][0].second;
    FOR(i, n)
    {
        FOR(j, n)
        {
            if(j>0)
            {
                if(matrix[i][j].first + m2[i][j-1].first < m2[i][j].first)
                {
                    m2[i][j].first = matrix[i][j].first + m2[i][j-1].first;
                    m2[i][j].second = m2[i][j-1].second + "R";
                }
                if(matrix[i][j].second + m5[i][j-1].first < m5[i][j].first)
                {
                    m5[i][j].first = matrix[i][j].second + m5[i][j-1].first;
                    m5[i][j].second = m5[i][j-1].second + "R";
                }
            }
            if(i>0)
            {
                if(matrix[i][j].first + m2[i-1][j].first < m2[i][j].first)
                {
                    m2[i][j].first = matrix[i][j].first + m2[i-1][j].first;
                    m2[i][j].second = m2[i-1][j].second + "D";
                }
                if(matrix[i][j].second + m5[i-1][j].first < m5[i][j].first)
                {
                    m5[i][j].first = matrix[i][j].second + m5[i-1][j].first;
                    m5[i][j].second = m5[i-1][j].second + "D";
                }
            }
        }
    }

    int mini = min(m2[n-1][n-1].first, m5[n-1][n-1].first);
    string path;

    if(m2[n-1][n-1].first == mini) path = m2[n-1][n-1].second;
    if(m5[n-1][n-1].first == mini) path = m5[n-1][n-1].second;

    cout << mini << endl;
    cout << path << endl;

    return 0;
}
