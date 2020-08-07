// https://www.hackerearth.com/pt-br/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/haunted/

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    int N, M, X, K = 0;
    map<int, int> ghosts;
    priority_queue<pii> prizes;
    int A[100100] = {0};

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> X;

        if(ghosts.count(X) == 0)
        {
            ghosts[X] = K;
            A[K]++;
            K++;
        }
        else
        {
            A[ghosts[X]]++;
        }

        prizes.push(make_pair(A[ghosts[X]], X));
        cout << prizes.top().second << ' ' << prizes.top().first << endl;
    }

    return 0;
}
