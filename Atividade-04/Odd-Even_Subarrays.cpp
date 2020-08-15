// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/odd-even-subarrays-72ad69db/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;

    cin >> n;
    int A[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    ll positive[n + 1] = {0};
    ll negative[n + 1] = {0};
    ll difference = 0, ans = 0;

    positive[0] = 1;

    for (size_t i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
            difference = difference + 1LL;
        else
            difference = difference - 1LL;

        if (difference < 0)
        {
            ans += negative[-difference];
            negative[-difference] = negative[-difference] + 1LL;
        }
        else
        {
            ans += positive[difference];
            positive[difference] = positive[difference] + 1LL;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
4
1 2 1 2

[1]
[1, 2] *
[1, 2, 1]
[1, 2, 1, 2] *
[2]
[2, 1] *
[2, 1, 2]
[1]
[1, 2] *
[2]

*/