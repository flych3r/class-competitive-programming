// https://www.hackerearth.com/pt-br/practice/data-structures/arrays/1-d/practice-problems/algorithm/modify-sequence/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n - 1; i++){
        if(A[i] <= A[i + 1]){
            A[i + 1] -= A[i];
            A[i] = 0;
        }
    }

    bool yes = true;
    for(int i = 0; i < n; i++){
        if(A[i] != 0){
            yes = false;
            break;
        }
    }

    cout << (yes ? "YES" : "NO") << endl;

}
