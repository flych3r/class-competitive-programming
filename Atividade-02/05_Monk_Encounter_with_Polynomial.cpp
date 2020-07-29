// https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ull f_x(ull a, ull b, ull c, ull x)
{
    return (a * (x * x)) + (b * x) + c;
}

int main(){
    ull t, a, b, c, k, x, x_best;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> k;
        if (c >= k)
        {
            x_best = 0;
        }
        else
        {
            ull l = 0, r = 10e6;
            while (l <= r)
            {
                x = l + (r - l) / 2;
                ull res = f_x(a, b, c, x);
                ull res_prev = f_x(a, b, c, x - 1);
                if (res >= k && res_prev < k)
                {
                    x_best = x;
                    break;
                }
                else if (res < k)
                {
                    l = x + 1;
                }
                else
                {
                    r = x - 1;
                }
            }
        }
        cout << x_best << endl;
    }

    return 0;
}
