/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    string str;
    int n;
    map<string,int> m;

    getline(cin,str);
    sscanf(str.c_str(),"%d",&n);

    map<string,int>::iterator it;
    for(int i=0; i<n; ++i)
    {
        getline(cin,str);
        it = m.find(str);
        if(it == m.end())
        {
            cout << "OK" << endl;
            m[str] = 1;
        }
        else
        {
            cout << str << it->second << endl;
            it->second++;
        }
    }

    return 0;
}
