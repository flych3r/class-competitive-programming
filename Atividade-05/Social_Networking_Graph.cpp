// https://www.hackerearth.com/pt-br/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 1;//1e6 + 1;

bool G[MAXN][MAXN];
bool visited[MAXN];
int N, E;

int bfs(int source, int t) {
    queue<pair<int, int>> visit;
    pair<int, int> f;
    int node, distance, t_count = 0;
    memset(visited, false, sizeof(visited));

    visit.push(make_pair(source, 0));
    visited[source] = true;

    while (!visit.empty())
    {
        f = visit.front();
        visit.pop();
        node = f.first, distance = f.second;

        if (distance == t) {
            t_count++;
            continue;
        }

        for (size_t i = 0; i < N; i++)
        {
            if (!visited[i] && distance < t && G[node][i]) {
                visit.push(make_pair(i, distance + 1));
                visited[i] = true;
            }
        }
    }

    return t_count;
}

int main(){
    cin >> N >> E;
    N++;
    int u, v, m, source, t;

    for (size_t i = 0; i < E; i++)
    {
        cin >> u >> v;
        G[u][v] = true;
        G[v][u] = true;
    }

    cin >> m;

    while (m--)
    {
        cin >> source >> t;
        cout << bfs(source, t) << endl;
    }

    return 0;
}