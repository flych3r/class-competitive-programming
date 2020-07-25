// https://www.hackerearth.com/pt-br/practice/data-structures/arrays/1-d/practice-problems/algorithm/no-sharing-capillary-82ed3fe2/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, p, q, r;

    cin >> t;
    while (t){
        cin >> n >> p >> q >> r;

        int A[n + 1];

        for(int i = 0; i <= n; i++){
            A[i] = 0;
        }

        for(int i = p; i <= n; i+=p){
            A[i] += 1;
        }
        for(int i = q; i <= n; i+=q){
            A[i] += 1;
        }
        for(int i = r; i <= n; i+=r){
            A[i] += 1;
        }

        int flights = 0;
        for(int i = 1; i <= n; i++){
            flights += (A[i] == 1);
        }

        cout << flights << endl;

        t--;
    }

}