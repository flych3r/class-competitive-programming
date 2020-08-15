// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/prateek-and-theories-3/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t, n;
    ll t1, t2;

    cin >> t;

    while (t--)
    {
        cin >> n;
        map<ll, ll> T;

        for (size_t i = 0; i < n; i++)
        {
            cin >> t1 >> t2;
            if (T.find(t1) != T.end()) T[t1]++;
            else T[t1] = 1;

            if (T.find(t2) != T.end()) T[t2]--;
            else T[t2] = -1;
        }

        ll m = 0, x = 0;
        for (const auto& a : T) {
            // cout << "T: " << a.first << ',' << a.second << endl;
            x += a.second;
            m = max(x, m);
        }

        cout << m << endl;
    }

    return 0;
}
