// https://www.hackerearth.com/pt-br/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-shino-and-pairs/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (A[i] < A[j])
            {
                count++;
                break;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (A[i] < A[j])
            {
                count++;
                break;
            }
        }
    }

    return 0;
}