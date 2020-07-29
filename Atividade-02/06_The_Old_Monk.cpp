#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int binarySearch(ull * A, int l, int r, ull x)
{
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (A[m] <= x && (m == 0 || A[m - 1] > x))
        {
            return m;
        }
        else if (A[m] > x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main(){
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ull A[n], b;
        int monkiness = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b;
            int i = binarySearch(A, 0, j, b);
            if (i > -1)
            {
                monkiness = max(monkiness, j - i);
            }
        }
        cout << monkiness << endl;

    }

    return 0;
}


// 2
// 9
// 7 7 3 3 3 2 2 2 1
// 8 8 7 7 5 5 4 3 2
// 6
// 6 5 4 4 4 4
// 2 2 2 2 2 2