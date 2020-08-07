// https://www.hackerearth.com/pt-br/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/pk-and-special-array-operation-1-7bd52ad1/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll N, Q, K, ai, total = 0;
    multiset <ll> A;
    multiset <ll> ::iterator it;

    cin >> N >> Q;

    for (size_t i = 0; i < N; i++)
    {
        cin >> ai;
        A.insert(ai);
        total += ai;
    }

    ll A_SUM[N], smallest, largest, diff;

    A_SUM[0] = total;
    for (size_t i = 1; i < N; i++)
    {
        it = A.begin();
        smallest = *it;
        A.erase(it);

        it = A.end();
        it--;
        largest = *it;
        A.erase(it);

        diff = largest - smallest;
        total -= smallest + largest;
        total += diff;
        A_SUM[i] = total;
        A.insert(diff);
    }

    while (Q--)
    {
        cin >> K;
        cout << A_SUM[K] << endl;
    }

    return 0;
}
