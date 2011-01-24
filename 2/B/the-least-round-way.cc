/*
* STATUS: ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <vector>

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORI(i,a,n) for(int i=a; i<n; ++i)
#define FORE(it,c) for(__typeof__(c.begin()) it=c.begin(); it!=c.end(); it++)

using namespace std;

#define MAX 100000

vector< vector< pair<int,int> > > matrix;

int power(long long number, long long base)
{
    int p = 0;
    while(number%base==0LL)
        number /= base,
        p++;
    return p;
}

int get_matrix(bool which, int r, int c)
{
    if(which)
        return matrix[r][c].second;
    return matrix[r][c].first;
}

// 2 = false, 5 = true
string find_path(int r, int c, bool which, vector< vector<int> > &mx)
{
    string path = "";
    while(r||c)
    {
        if(r>0 && mx[r][c] - get_matrix(which,r,c) == mx[r-1][c])
        {
            r--;
            path = "D" + path;
        }
        else if(c>0 && mx[r][c] - get_matrix(which,r,c) == mx[r][c-1])
        {
            c--;
            path = "R" + path;
        }
    }
    return path;
}

int main()
{
    bool zero = false;
    int n, zj;
    long long k;

    scanf("%d", &n);

    matrix = vector< vector< pair<int,int> > >(n, vector< pair<int,int> >(n));
    vector< vector<int> > m2(n, vector<int>(n, MAX));
    vector< vector<int> > m5(n, vector<int>(n, MAX));

    FOR(i, n)
    {
        FOR(j, n)
        {
            scanf("%I64d", &k);
            if(k==0LL) zero = true, zj = j, k = 10LL;
            matrix[i][j] = make_pair(power(k, 2LL), power(k, 5LL));
        }
    }

    m2[0][0] = matrix[0][0].first, m5[0][0] = matrix[0][0].second;
    FOR(i, n)
    {
        FOR(j, n)
        {
            if(j>0)
            {
                m2[i][j] = min(m2[i][j], matrix[i][j].first  + m2[i][j-1]);
                m5[i][j] = min(m5[i][j], matrix[i][j].second + m5[i][j-1]);
            }
            if(i>0)
            {
                m2[i][j] = min(m2[i][j], matrix[i][j].first  + m2[i-1][j]);
                m5[i][j] = min(m5[i][j], matrix[i][j].second + m5[i-1][j]);
            }
        }
    }

    int mini = min(m2[n-1][n-1], m5[n-1][n-1]);

    string path;

    if(zero && mini>1)
    {
        mini = 1;
        FOR(j,zj) path = path + "R";
        FOR(i,n-1) path = path + "D";
        FORI(j,zj,n-1) path = path + "R";
    }
    else
    {
        if(m5[n-1][n-1] == mini) path = find_path(n-1, n-1, true, m5);
        else if(m2[n-1][n-1] == mini) path = find_path(n-1, n-1, false, m2);
    }
    cout << ((mini<0)?1:mini) << endl;
    cout << path << endl;

    return 0;
}
