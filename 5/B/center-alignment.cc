/*
* STATUS = ACCEPTED
*/

#include <cstdio>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

#define FOR(i,n)   for(int i=0; i<n; ++i)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define SZ(c)      ((int)c.size())

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("center-alignment.in","r",stdin);
    #endif

    string str;
    list<string> text;
    int max_size = -1;

    while(getline(cin,str))
    {
        text.push_back(str);
        max_size = max(max_size, SZ(str));
    }

    bool side = false;
    FOR(i,max_size+2) printf("*"); printf("\n");
    FORE(it,text)
    {
        int space = max_size - (int)it->size();
        int left =  (space + 1 * side) / 2;
        int right =  space - left;

        printf("*");
        FOR(i,left) printf(" ");
        printf("%s",it->c_str());
        FOR(i,right) printf(" ");
        printf("*\n");

        if((int)it->size() && space%2)
            side = !side;
    }
    FOR(i,max_size+2) printf("*"); printf("\n");

    return 0;
}
