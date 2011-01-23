/*
* STATUS = WRONG ANSWER
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define sqr(i) ((i)*(i))
#define EPS 1E-6

double gcd(double a, double b)
{
    if(abs(b) < EPS) return a;
    return gcd(b, a - floor(a/b) * b);
}

double distancia(double x1, double y1, double x2, double y2)
{
    return sqr(x1 - x2) + sqr(y1 - y2);
}

int main()
{
    double x[3], y[3], a[3];

    FOR(i, 3)
    {
        cin >> x[i] >> y[i];
    }

    double A1 = y[1] - y[0], B1 = x[0] - x[1], D1 = A1 * ((y[0] + y[1]) / 2.0) - B1 * ((x[0] + x[1]) / 2.0);
    double A2 = y[2] - y[0], B2 = x[0] - x[2], D2 = A2 * ((y[0] + y[2]) / 2.0) - B2 * ((x[0] + x[2]) / 2.0);

    double Y = (D1 * B2 - D2 * B1) / (A1 * B2 - A2 * B1);
    double X = (D1 * A2 - D2 * A1) / (A1 * B2 - A2 * B1);

//    cout << X << " " << Y << endl;

    double r = distancia(x[0], y[0], X, Y);

    FOR(i, 3)
    {
        int j = (i + 1) % 3;
        double CC = distancia(x[i],y[i],x[j],y[j]), AA = r /*distancia(x[i],y[i],X,Y)*/, BB = r /*distancia(X,Y,x[j],y[j])*/;
//        cout << A << " " << B << " " << C << endl;
        a[i] = acos((AA + BB - CC) / (2.0 * sqrt(AA) * sqrt(BB)));
//        cout << a[i] << endl;
    }

    double g = gcd(gcd(a[0], a[1]), a[2]);
    double n = ((2.0 * M_PI) / g);

    double A = (r * n * sin(g)) / 2.0;

    printf("%llf\n",A);

    return 0;
}
