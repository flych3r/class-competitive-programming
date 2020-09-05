// https://www.hackerearth.com/pt-br/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/hell-1/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1;

int n_dividers[MAXN];
int prefix_sum[MAXN];


void solve(){
    for(int i = 1; i < MAXN; i++){
        for(int j = i; j < MAXN; j += i){
            n_dividers[j] += 1;
        }
    }

    for(int i = 2; i < MAXN; i++){
        if(n_dividers[i] == 2){
            prefix_sum[i] = 1;
        }
    }

    for(int i = 2; i < MAXN; i++){
        prefix_sum[i] = prefix_sum[i] + prefix_sum[i-1];
    }
}

int prefix_sum_query(int L, int R){
    return prefix_sum[R] - prefix_sum[L - 1];
}

int main(){
    int Q, L, R;

    scanf("%d", &Q);

    solve();

    while(Q--) {
        scanf("%d %d", &L, &R);
        if (L > R) swap(L, R);
        printf("%d\n", prefix_sum_query(L, R));
    }

    return 0;
}
