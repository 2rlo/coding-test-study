// BOJ 18430 무기 공학 https://www.acmicpc.net/problem/18430
// Created by 윤혜경 on 3/2/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
#define MAX 5
using namespace std;

int N, M, res;
int wood[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };
int nx[8] = { 0, 1, 0, -1, -1, 0, 1, 0};
int ny[8] = { -1, 0, -1, 0, 0, 1, 0, 1};

void backtrack(int x, int y, int sum) {
    res = max(res, sum);

    if (y == M) {
        x++;
        y = 0;
    }

    if (x == N)
        return;

    if(!visited[x][y]) {
        for (int i = 0; i < 8; i = i + 2) {
            int nx1 = x + nx[i];
            int ny1 = y + ny[i];
            int nx2 = x + nx[i + 1];
            int ny2 = y + ny[i + 1];

            if (nx1 >= 0 && nx1 < N && nx2 >= 0 && nx2 < N && ny1 >= 0 && ny1 < M && ny2 >= 0 && ny2 < M) {
                if (visited[nx1][ny1] || visited[nx2][ny2])
                    continue;
                visited[x][y] = true;
                visited[nx1][ny1] = true;
                visited[nx2][ny2] = true;

                int cal = wood[x][y] * 2 + wood[nx1][ny1] + wood[nx2][ny2];

                backtrack(x, y + 1, sum + cal);


                visited[x][y] = false;
                visited[nx1][ny1] = false;
                visited[nx2][ny2] = false;
            }
        }
    }
    backtrack(x, y + 1, sum);
}

int main() {
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> wood[i][j];

    backtrack(0, 0, 0);

    cout << res;
}