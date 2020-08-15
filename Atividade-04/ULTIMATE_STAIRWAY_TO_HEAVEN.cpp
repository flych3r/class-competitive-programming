// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/ultimate-stairway-to-heaven/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;


int main(){

    int n;
    cin >> n;
    int A[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    ll sum = 0, dp[n] = {0}, tmp[n] = {0};

    dp[0] = 1;

    for (size_t i = 0; i < n; i++)
    {
        tmp[i + 1] = (tmp[i + 1] + dp[i]) % MOD;
        if(i + 1 + A[i] < n )
            tmp[i + 1 + A[i]] = (MOD + tmp[i + 1 + A[i]] - dp[i]) % MOD;
        sum = (sum + tmp[i + 1]) % MOD;
        dp[i + 1] = sum;
    }

	cout << dp[n-1] << endl;

    return 0;
}