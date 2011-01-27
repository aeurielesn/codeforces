/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORE(it,c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define REPEAT(str,n) FOR(i,n) answer.push_back(str);

typedef pair<int,int> square;

void read_square(square &s)
{
    string str;
    getline(cin, str);
    s.first = str[1] - 1, s.second = str[0] - 'a';
}

int main()
{
    int tot = 0;
    square s, t;
    list<string> answer;

    read_square(s), read_square(t);

    if(s.first < t.first && s.second < t.second)
    {
        int mv = min(t.first - s.first, t.second - s.second);
        REPEAT("RU", mv);
        s.first += mv, s.second += mv, tot += mv;
    }
    else if(s.first < t.first && s.second > t.second)
    {
        int mv = min(t.first - s.first, s.second - t.second);
        REPEAT("LU", mv);
        s.first += mv, s.second -= mv, tot += mv;
    }
    else if(s.first > t.first && s.second > t.second)
    {
        int mv = min(s.first - t.first, s.second - t.second);
        REPEAT("LD", mv);
        s.first -= mv, s.second -= mv, tot += mv;
    }
    else if(s.first > t.first && s.second < t.second)
    {
        int mv = min(s.first - t.first, t.second - s.second);
        REPEAT("RD", mv);
        s.first -= mv, s.second += mv, tot += mv;
    }

    if(s.first == t.first && s.second < t.second)
    {
        int mv = t.second - s.second;
        REPEAT("R", mv);
        s.second += mv, tot += mv;
    }
    else if(s.first < t.first && s.second == t.second)
    {
        int mv = t.first - s.first;
        REPEAT("U", mv);
        s.first += mv, tot += mv;
    }
    else if(s.first > t.first && s.second == t.second)
    {
        int mv = s.first - t.first;
        REPEAT("D", mv);
        s.first -= mv, tot += mv;
    }
    else if(s.first == t.first && s.second > t.second)
    {
        int mv = s.second - t.second;
        REPEAT("L", mv);
        s.second -= mv, tot += mv;
    }

    cout << answer.size() << endl;
    FORE(it, answer)
    {
        cout << *it << endl;
    }

    return 0;
}
