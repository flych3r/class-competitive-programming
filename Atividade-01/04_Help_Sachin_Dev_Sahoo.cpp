// https://www.hackerearth.com/pt-br/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/minimum-flips/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, k, n;
    string s;

    cin >> t;
    while(t){
        cin >> s >> k;
        n = s.length();
        bool A[n];
        for(int i = 0; i < n; i++)
            A[i] = s[i] == '1';

        int flips = 0;
        for(int i = 0; i <= n - k; i++){
            if(!A[i]){
                flips++;
                for(int j = i; j < i + k; j++)
                    A[j] = !A[j];
            }
        }

        for(int i = 0; i < n; i++){
            if(!A[i]){
                flips = -1;
                break;
            }
        }
        cout << flips << endl;

        t--;
    }
}
