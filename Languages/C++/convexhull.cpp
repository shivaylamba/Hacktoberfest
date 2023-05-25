// cách thầy Hùng;
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int maxN = 1e5 + 2;
long long n, i, a[maxN], b[maxN], c[maxN], d[maxN], A, B, Max, Min, cnt1(0), cnt2(0), cnt(0), res[maxN];

long double Area (long long x, long long y)
{
    long double u;
    u = (a[y] - a[x]) * (b[x] + b[y]) / 2.0;
    return u;
}

bool LF (long long p, long long q)
{
    return (a[p] < a[q] || (a[p] == a[q] && b[p] < b[q]));
}

void Init()
{
    cin >> n;
    A = B = 0; Max = -1e18; Min = 1e18;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        if (a[i] <= Min) Min = a[i], B = i;
        if (a[i] >= Max) Max = a[i], A = i;
    }
}

void Solve()
{
    for (i = 1; i <= n; i++)
    {
        if (Area(A, i) + Area(i, B) + Area (B, A) < 0) c[++cnt1] = i;
        else if (Area(A, i) + Area(i, B) + Area (B, A) > 0) d[++cnt2] = i;
    }
    sort (c + 1, c + cnt1 + 1, LF);
    sort (d + 1, d + cnt2 + 1, LF);
}

void Solve2()
{
    vector <long long> v;
    v.push_back(B); d[++cnt2] = A;
    for (i = 1; i <= cnt2; i++)
    {
        while (v.size() > 1)
        {
            if (Area(v[v.size() - 2], v[v.size() - 1]) + Area(v[v.size() - 1], d[i]) + Area(d[i], v[v.size() - 2]) >= 0)
                v.pop_back();
            else break;
        }
        v.push_back(d[i]);
    }
    for (i = 0; i < v.size(); i++) res[++cnt] = v[i];
    v.clear();
    v.push_back(B); c[++cnt1] = A;
    for (i = 1; i <= cnt1; i++)
    {
        while (v.size() > 1)
        {
            if (Area(v[v.size() - 2], v[v.size() - 1]) + Area(v[v.size() - 1], c[i]) + Area(c[i], v[v.size() - 2]) <= 0)
                v.pop_back();
            else break;
        }
        v.push_back(c[i]);
    }
    if (v.size() > 2)
        for (i = v.size() - 2; i > 0; i--) res[++cnt] = v[i];
}

void Trace()
{
    long double kq(0);
    long long Min2 = 1e18, k;
    for (i = 2; i <= cnt; i++) kq += Area(res[i], res[i - 1]); kq += Area(res[1], res[cnt]);
    for (i = 1; i <= cnt; i++)
    {
        if (Min2 >= b[res[i]])
        {
            if (Min2 == b[res[i]])
            {
                if (a[res[i]] < a[res[k]]) Min2 = b[res[i]], k = i;
            }
            else if (Min2 > b[res[i]]) Min2 = b[res[i]], k = i;
        }
    }
    cout << cnt << '\n';
    cout << fixed << setprecision(1) << abs(kq) << '\n';
    for (i = k; i <= cnt; i++) cout << a[res[i]] << " " << b[res[i]] << '\n';
    for (i = 1; i < k; i++) cout << a[res[i]] << " " << b[res[i]] << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("convexhull.inp", "r", stdin);
    //freopen("convexhull.out", "w", stdout);

	Init();
	Solve();
	Solve2();
	Trace();
}
//Date 10 Month 5 Year 2017

