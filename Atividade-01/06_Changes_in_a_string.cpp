// https://www.hackerearth.com/pt-br/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/ab-string-5f6b213a/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){

        string S;
        int n;

        cin >> n;
        cin >> S;
        int A[n], B[n], swaps[n];

        A[0] = S[0] == 'A';
        B[n - 1] = S[n - 1] == 'B';

        for(int i = 1; i < n; i++)
            A[i] = A[i - 1] + (S[i] == 'A');

        for(int i = n - 2; i >= 0; i--)
            B[i] = B[i + 1] + (S[i] == 'B');

        for(int i = 0; i < n; i++)
            swaps[i] = n - A[i] - B[i];

        cout << *min_element(swaps, swaps + n) << endl;

        t--;
    }
}
