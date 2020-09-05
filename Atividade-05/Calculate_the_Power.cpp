// https://www.hackerearth.com/pt-br/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/calculate-the-power/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll mod_exponentiation(ll x, ll pow){
    if(pow == 0) return 1;
    if(pow % 2) return (x * mod_exponentiation(x, pow - 1)) % MOD;
    ll ans = mod_exponentiation(x, pow / 2);
    return (ans * ans) % MOD;
}

int main(){
    ll A, B;

    cin >> A >> B;

    cout << mod_exponentiation(A, B) << endl;

    return 0;
}

