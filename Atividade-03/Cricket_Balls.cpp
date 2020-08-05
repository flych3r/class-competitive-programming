// https://www.hackerearth.com/pt-br/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/cricket-balls/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll T, N, K;

    cin >> T;

    while (T--)
    {
        cin >> N;
        ll A[N], count[100001] = {0};
        for (size_t i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cin >> K;

        for (size_t i = 0; i < N; i++)
        {
            count[A[i]]++;
        }

        ll selections = 0;
        for (size_t i = 0; i < N; i++)
        {
            if (K > A[i])
            {
                selections += count[K - A[i]];
                if (count[K - A[i]] > 0 && K - A[i] == A[i])
                    selections--;
            }
        }
        selections /= 2;

        cout << selections << endl;

    }

    return 0;
}
