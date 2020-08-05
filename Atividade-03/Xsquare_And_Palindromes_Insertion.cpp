// https://www.hackerearth.com/pt-br/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-palindromes-insertion/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    string str;

    cin >> T;

    while (T--)
    {
        cin >> str;
        int ascii[128] = {0};

        for (auto &&c : str)
        {
            ascii[(int) c]++;
        }

        int odd = -1;
        for (size_t i = 0; i < 128; i++)
        {
            odd += ascii[i] % 2 != 0;
        }

        cout << max(0, odd) << endl;

    }

    return 0;
}
