// https://www.hackerearth.com/pt-br/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/ashu-and-prime-factors-4/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;

bool is_composite[MAXN];
int count_min_prime_factor[MAXN];

void solve(){
    is_composite[1] = true;
    for(int i = 2; i < MAXN; i++){
        if(!is_composite[i]){
            count_min_prime_factor[i] = 1;
            for(int j = i+i; j < MAXN; j += i){
                if(!is_composite[j]){
                    count_min_prime_factor[i] += 1;
                    is_composite[j] = true;
                }
            }
        }
    }
}

int main(){
    int T;
    cin >> T;

    solve();

    while(T--){
        int X;
        cin >> X;
        cout << count_min_prime_factor[X] << endl;
    }
}
