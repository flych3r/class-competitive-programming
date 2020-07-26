// https://www.hackerearth.com/pt-br/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/bob-and-profit-fd9f0ee3/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
	    vector<long long> A(n);
        long long preSum[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];

        sort(A.begin(), A.end());

        preSum[0] = 0;
        for(int i = 1; i < n; i++){
            preSum[i] = preSum[i - 1] + A[i - 1];
        }

        long long m = INT_MIN;
        for(int i = 0; i < n; i++){
            m = max(m, A[i] * (n - i) - preSum[i]);
        }

        cout << m << endl;

        t--;
    }

}