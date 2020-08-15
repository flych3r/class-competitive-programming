// https://www.hackerearth.com/pt-br/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/lets-begin/

#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 1;

const int M = 4;
const int coins[M] = {2, 3, 5, 7};

int table[MAX_N];

void minCoins()
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    // int table[V+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i=1; i<=MAX_N; i++)
        table[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (int i=1; i<=MAX_N; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<M; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    table[1] = -1;
}

int main()
{
    minCoins();
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        cout << table[x] << endl;
    }
    return 0;
}

/*
4
7
10
14
11
*/