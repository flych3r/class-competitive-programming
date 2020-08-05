// https://www.hackerearth.com/pt-br/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/maximum-occurrence-9/

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    int ascii[128] = {0};

    getline(cin, str);

    for (auto &&c : str)
    {
        ascii[(int) c]++;
    }

    auto e = max_element(ascii, ascii + 128);
    cout << (char) (e - ascii) << ' ' << *e << endl;

    return 0;
}