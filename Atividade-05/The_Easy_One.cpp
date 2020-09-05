// https://www.hackerearth.com/pt-br/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-easy-one-0de35805/

/*
MOD = 1e9 + 7
L = tamanho de N
fat = frequencia de i em N
inv_modular = x ^ (M - 2)

divisor = ((fat(0)! + fat(1)! + ... + fat(9)!) % MOD)
dividendo = (L! % MOD)

resp = (dividendo * inv_modular(divisor)) % MOD
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
ll count_digits[10];

ll count_digits_in_string(string number){
    ll size = 0;

    for(int i = 0; i <= 9; i++){
        count_digits[i] = 0;
    }

    for(const char c : number){
        size++;
        count_digits[int(c - '0')]++;
    }

    return size;
}

ll mod_exponentiation(ll x, ll pow){
    if(pow == 0) return 1;
    if(pow % 2) return (x * mod_exponentiation(x, pow - 1)) % MOD;
    ll ans = mod_exponentiation(x, pow / 2);
    return (ans * ans) % MOD;
}

ll inverse_modular(ll x){
    return mod_exponentiation(x, MOD - 2);
}

ll factorial(ll x) {
    ll fat = 1;
    for(ll i = 1; i <= x; i++){
        fat = (fat * i) % MOD;
    }
    return fat;
}

ll different_numbers(string number){

    ll size = count_digits_in_string(number);
    ll dividend = factorial(size);

    ll divider = 1;
    for(int i = 0; i <= 9; i++){
        ll d = factorial(count_digits[i]);
        divider = (divider * d) % MOD;
    }

    return (dividend * inverse_modular(divider)) % MOD;
}

int main(){
    int T;
    string number;
    cin >> T;

    while(T--){
        cin >> number;
        cout << different_numbers(number) << endl;
    }

    return 0;
}
