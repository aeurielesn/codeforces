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

#define ll(c) ((long long)c)

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("chat-server's-outgoing-traffic.in","r",stdin);
    #endif

    long long l = 0;
    string str, msg;
    set<string> users;

    while(getline(cin,str))
    {
        if(str[0]=='+')
        {
            str[0] = '@';
            users.insert(str);
        }
        else if(str[0]=='-')
        {
            str[0] = '@';
            users.erase(str);
        }
        else
        {
            string::size_type colon = str.find(":",0);
            if( colon != string::npos ) {
                l += (ll(str.size()) - ll(colon) - 1LL) * ll(users.size());
            }
        }
    }

    printf("%lld\n", l);
    return 0;
}
