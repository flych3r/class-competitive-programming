// https://www.hackerearth.com/pt-br/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/waves-b18625d7/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 1;

int M[MAXN][MAXN];
int R, C;

void bfs(int x, int y) {

    int i, j;
    queue<pair<int, int>> visit;
    pair<int, int> f;

    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            M[i][j] = -1;
    M[x][y] = 0;

    visit.push(make_pair(x, y));
    while (!visit.empty())
    {

        f = visit.front();
        visit.pop();

        int x = f.first, y = f.second;

        int n = M[x][y];
        for (i = x - 1; i <= x + 1; i++)
        {
            for (j = y - 1; j <= y + 1; j++)
            {
                if (i >= R || j >= C) continue;
                if (i < 0 || j < 0) continue;
                if (i == x && j == y) continue;
                if (M[i][j] != -1) continue;
                M[i][j] = n + 1;
                visit.push(make_pair(i, j));
            }
        }
    }
}

int main(){
    int Ci, Cj;

    cin >> R >> C >> Ci >> Cj;

    bfs(Ci, Cj);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
