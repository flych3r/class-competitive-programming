// https://www.hackerearth.com/pt-br/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n, k;
    cin >> t;

    while(t) {
        cin >> n >> k;

        int A[n];
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }

        cout << max(0, k - *min_element(A, A + n)) << endl;
        t--;
    }

}
