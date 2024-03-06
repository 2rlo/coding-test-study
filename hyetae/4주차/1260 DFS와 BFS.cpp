// BOJ 1260 DFS와 BFS https://www.acmicpc.net/problem/1260
// Created by 윤혜경 on 3/6/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

#define MAX 1'001
int N, M, V, a, b;
int graph[MAX][MAX];
int visited[MAX];

void dfs(int v) {
    visited[v] = 1;
    cout << v << ' ';

    for (int i = 1; i < N + 1; i++)
        if (!visited[i] && graph[v][i])
            dfs(i);
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;
    cout << v << ' ';

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i < N + 1; i++){
            if (!visited[i] && graph[x][i]) {
                q.push(i);
                visited[i] = 1;
                cout << i << ' ';
            }
        }
    }
}

int main() {
    fastio;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    memset(visited, 0, sizeof(visited));
    dfs(V);
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    bfs(V);
}