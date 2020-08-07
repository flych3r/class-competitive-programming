// https://www.hackerearth.com/pt-br/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-champions-league/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll M, N, s, total = 0;
    priority_queue <ll, vector<ll>, less<ll>> seats;

    cin >> M >> N;
    for (size_t i = 0; i < M; i++)
    {
        cin >> s;
        seats.push(s);
    }

    for (size_t i = 0; i < N; i++)
    {
        s = seats.top();
        seats.pop();
        total += s;
        s--;
        seats.push(s);
    }

    cout << total << endl;

    return 0;
}