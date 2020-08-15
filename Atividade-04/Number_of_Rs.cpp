// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/number-of-rs-1/

#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

int main(){
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int size = s.size();
        int a[size];
        int count = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (s[i] == 'R')
            {
                a[i] = -1;
                count++;
            }
            else
            {
                a[i] = 1;
            }
        }

        int flips = maxSubArraySum(a, size);
        if (count < size)
            cout << count + flips << endl;
        else
            cout << count - 1 << endl;
    }

   return 0;
}
