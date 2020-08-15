// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/sumits-sub-array-and-sub-sequence/

#include <bits/stdc++.h>

using namespace std;

pair<int, int> maxSubArraySubsequenceSum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    int max_negative = INT_MIN, max_all = 0;
    bool all_negative = true;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;

        if (a[i] > 0)
        {
            all_negative = false;
            max_all += a[i];
        }
        else
        {
            max_negative = max(a[i], max_negative);
        }
    }
    if (all_negative)
        max_all = max_negative;

    return make_pair(max_so_far, max_all);
}

int main(){
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int A[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        pair<int, int> m = maxSubArraySubsequenceSum(A, n);
        cout << m.first << ' ' << m.second << endl;
    }
    return 0;
}
