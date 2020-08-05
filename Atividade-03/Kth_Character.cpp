// https://www.hackerearth.com/pt-br/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/kth-character-2/

#include <bits/stdc++.h>

using namespace std;

int main(){
    long N, Q, L, R, K;
    string S, substring;

    cin >> N >> Q >> S;

    long counting_table[N + 1][26] = {0};

    for (size_t i = 1; i <= N; i++)
    {
        counting_table[i][S[i - 1] - 'a']++;
        for (size_t j = 0; j < 26; j++)
        {
            counting_table[i][j] += counting_table[i - 1][j];
        }
    }

    while (Q--)
    {
        cin >> L >> R >> K;

        long position = 0;
        int c;
        for (c = 0; c < 26; c++)
        {
            position += counting_table[R][c] - counting_table[L - 1][c];

            if (position >= K) break;
        }

        cout << (char) (c + 'a') << endl;
    }

    return 0;
}
