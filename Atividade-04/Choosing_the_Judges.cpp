// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/choosing-the-judges-7/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int T, N, c = 0;
    cin >> T;
    while (T--)
    {
        c++;
        cin >> N;
        ll X[N], dp[N], max_votes;
        for (size_t i = 0; i < N; i++)
        {
            cin >> X[i];
        }
        dp[0] = X[0];
        if (N == 1)
        {
            max_votes = X[0];
        }
        else
        {
            max_votes = max(X[0], X[1]);
            dp[1] = max_votes;
            for (size_t i = 2; i < N; i++)
            {
                dp[i] = max(dp[i - 1], dp[i - 2] + X[i]);
                dp[i] = max(dp[i], dp[i - 2] + X[i]);
                max_votes = max(dp[i], max_votes);
            }
        }
        printf("Case %d: %lld\n", c, max_votes);
    }

    return 0;
}

/*
3
5
1 2 3 4 5
1
10
7
9961 491 2995 11942 4827 5436 32391
# 54294
*/