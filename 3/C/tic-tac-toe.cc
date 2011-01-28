/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define SZ(c) ((int)c.size())

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("tic-tac-toe.in","r",stdin);
    #endif

    vector<string> board(3);

    int x = 0, o = 0, x3 = 0, o3 = 0;

    FOR(i,3)
    {
        getline(cin,board[i]);
        FOR(j,3)
        {
            if(board[i][j]=='X') ++x;
            else if(board[i][j]=='0') ++o;
        }
    }

    FOR(i,3)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            x3 += board[i][0]=='X', o3 += board[i][0]=='0';

        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            x3 += board[0][i]=='X', o3 += board[0][i]=='0';
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        x3 += board[1][1]=='X', o3 += board[1][1]=='0';

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        x3 += board[1][1]=='X', o3 += board[1][1]=='0';


    if((x - o < 0 || x - o > 1) || (x3 && o3) || (x3 && x - o != 1) || (o3 && x - o != 0))
    {
        printf("illegal");
    }
    else if(x3)
    {
        printf("the first player won");
    }
    else if(o3)
    {
        printf("the second player won");
    }
    else if(x - o == 0)
    {
        printf("first");
    }
    else if((x + o < 9) && (x - o == 1))
    {
        printf("second");
    }
    else
    {
        printf("draw");
    }
    printf("\n");

    return 0;
}
