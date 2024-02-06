// BOJ 17836 공주님을 구해라! https://www.acmicpc.net/problem/17836
// Created by 윤혜경 on 1/24/24.

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int res = 10001;
int N, M, T;
int graph[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (graph[nx][ny] == 1)
                    continue;

                if (graph[nx][ny] == 2)
                    res = min(res, visited[a][b] + (N - nx + M - ny) - 2);

                if (!visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = visited[a][b] + 1;
                }
            }
        }
    }

    if (visited[N - 1][M - 1] > 0)
        res = min(res, visited[N - 1][M - 1] - 1);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> T;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];

    bfs(0, 0);
    if (res <= T)
        cout << res;
    else
        cout << "Fail";
}