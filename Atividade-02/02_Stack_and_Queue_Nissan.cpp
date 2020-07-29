// https://www.hackerearth.com/pt-br/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/staque-1-e790a29f/description/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;
    int A[N];
    ll total = 0LL, max = 0LL;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (i < K)
        {
            total += A[i];
        }
    }

    max = total;

    for (int i = 0; i < K - 1; i++)
    {
        total = total - A[K - i - 1] + A[N - i - 1];
        if (total >= max)
        {
            max = total;
        }

    }

    cout << max << endl;

    return 0;
}