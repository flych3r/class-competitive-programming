// https://www.hackerearth.com/pt-br/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/k-friends-89908017/e/

#include<bits/stdc++.h>

using namespace std;

long long Gifts (vector<int> S, int K) {

    sort(S.begin(), S.end());
    long long gifts = accumulate(S.begin(), S.begin() + K, 0LL);
    gifts += (long long)S[K - 1] * (long long)(S.size() - K);
    return gifts;
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> S(N);
        for(int i_S=0; i_S<N; i_S++)
        {
        	cin >> S[i_S];
        }
        int K;
        cin >> K;

        long long out_;
        out_ = Gifts(S, K);
        cout << out_;
        cout << "\n";
    }
}