// https://www.hackerearth.com/pt-br/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-confused-monk/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 1;

const ll MOD = 1e9 + 7;
ll seq[MAXN];

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main(){
    int N;
    ll fx = 1, gx = 0, ans = 1, a;

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> a;

        fx = (fx * a) % MOD;
        gx = gcd(gx, a);
    }

    for(int i = 1; i <= gx; i++){
        ans = (ans * fx) % MOD;
    }

    cout << ans << endl;

    return 0;
}
