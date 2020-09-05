// https://www.hackerearth.com/pt-br/practice/math/number-theory/primality-tests/practice-problems/algorithm/ultra-prime/

#include <bits/stdc++.h>
using namespace std;

const int MAXN =  1e6 + 1;
bool is_composite[MAXN];
int prefix_sum[MAXN];

int n_digits(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x = x / 10;
    }
    return ans;
}

void solve(){
    is_composite[1] = true;
    for(int i = 2; i < MAXN; i++){
        if(!is_composite[i]){
            for(int j = i+i; j < MAXN; j += i){
                is_composite[j] = true;
            }
        }
    }

    for(int i = 1; i < MAXN; i++){
        prefix_sum[i] = (!is_composite[i] and !is_composite[n_digits(i)]) + prefix_sum[i-1];
    }
}

int prefix_sum_query(int L, int R){
    return prefix_sum[R] - prefix_sum[L - 1];
}

int main(){
    int T;
    cin >> T;

    solve();

    while(T--){
        int L, R;
        cin >> L >> R;

        cout << prefix_sum_query(L, R) << endl;
    }

    return 0;
}
