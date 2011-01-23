/*
* STATUS = ACCEPTED
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define greater(a,b) (((a/b)*b<a)?(a/b)+1:(a/b))

long long flagstones(long long N, long long M, long long A)
{
    return greater(M, A) * greater(N, A);
}

int main()
{
    long long N, M, A, cnt = 0;

    scanf("%I64d%I64d%I64d", &N, &M, &A);

    printf("%I64d\n", flagstones(N, M, A));

    return 0;
}
