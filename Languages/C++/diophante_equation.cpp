#include <iostream>

using namespace std;

long long KetQua(long long Max, long long a)
{
    if (Max % a == 0) return Max / a;
    else return Max / a + 1;
}

long long NghiemMax(long long yM, long long b, long long xM, long long a)
{
    long long du = b - (-xM % b);
    long long Max = yM - (du - xM) * a / b;
    cout << KetQua(Max, a);
}

int main()
{
     long long a, b, m, n, xM(1), yM(0), xN(0), yN(1), q, xR, yR, r, x, y, Max;
     unsigned long long c;
     cin >> a >> b >> c;
     m = a; n = b;
     while(n != 0)
     {
        q = m / n; r = m - q * n;
        xR = xM - q * xN; yR = yM - q * yN;
        m = n; xM = xN; yM = yN;
        n = r; xN = xR; yN = yR;
     }
     if (c % m != 0) cout << 0;
     else

     {
        a /= m; b /= m; c /= m;
        xM *= c; yM *= c;
        if (xM >= yM) NghiemMax(xM, a, yM, b);
        else NghiemMax(yM, b, xM, a);
     }
}

