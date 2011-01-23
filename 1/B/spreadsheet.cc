/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)

void conversion(string str)
{
    int d1, d2;
    char s1[100], s2[100];
    int cnt = sscanf(str.c_str(), "%[A-Z]%d%[A-Z]%d", s1, &d1, s2, &d2);
    if(cnt == 2)
    // CR -> RXCY
    {
        int len = strlen(s1), r = d1, c = 0, pow = 1;
        FOR(i, len)
        {
            int pos = s1[len - i - 1] - 'A' + 1;
            c += pos * pow;
            pow *= 26;
        }
        printf("R%dC%d\n", r, c);
    }
    else
    // RXCY -> CR
    {
        int r = d1;
        string c = "";
        while(d2)
        {
            int mod = ((d2 - 1) % 26) + 1;
            c += (char)('A' + mod - 1);
            d2 = (d2 - mod) / 26;
        }
        reverse(c.begin(), c.end());
        cout << c << r << endl;
    }
}

int main()
{
    int N;
    string current;

    getline(cin, current);
    sscanf(current.c_str(), "%d", &N);

    FOR(i, N)
    {
        getline(cin, current);
        conversion(current);
    }

    return 0;
}
