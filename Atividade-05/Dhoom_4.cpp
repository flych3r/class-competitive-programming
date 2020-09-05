// https://www.hackerearth.com/pt-br/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e5;
const int MAXN = 1e3 + 1;

int other_keys[MAXN];
int times[MOD + 1];

int main(){

    int my_key, lock_key, N;

    cin >> my_key >> lock_key >> N;

    int other_keys[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> other_keys[i];
    }
    memset(times, -1, sizeof(times));
    times[my_key] = 0;

    queue<int> bfs;
    bfs.push(my_key);

    while(!bfs.empty()){
        int key_value = bfs.front();
        bfs.pop();

        if(key_value == lock_key) break;

        for(int i = 0; i < N; i++){
            ll new_value = other_keys[i];

            new_value = new_value * key_value;
            new_value %= MOD;
            if(times[new_value] == -1) {
                times[new_value] = times[key_value] + 1;
                bfs.push(new_value);
            }
        }
    }

    cout << times[lock_key] << endl;

    return 0;
}
