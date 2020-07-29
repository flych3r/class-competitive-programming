// https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/c-impresses-everyone/
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
int main(){
    ull n, q, x, even;
    cin >> n;
    even = n % 2 == 0;
    ull A[n];
    for (ull i = 0; i < n; i++)
    {
        cin >> A[i];
    }
 
    ull cumSum[n];
    cumSum[0] = A[n - 1];
    for (ull i = 1; i < n; i++)
    {
        cumSum[i] = cumSum[i - 1] + A[n - i - 1];
    }
 
    cin >> q;
    while (q--)
    {
        cin >> x;
        ull l = 0, r = n - 1, m, m_best = 0;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (cumSum[m] >= x && (m == 0 || cumSum[m - 1] < x))
            {
                m_best = m;
                break;
            }
            else if (cumSum[m] < x)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if ((m_best + even) % 2 == 0)
        {
            cout << 'A' << endl;
        }
        else
        {
            cout << 'B' << endl;
        }
    }
 
    return 0;
}