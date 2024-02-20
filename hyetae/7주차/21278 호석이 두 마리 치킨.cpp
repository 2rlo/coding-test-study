// 21278 호석이 두 마리 치킨 https://www.acmicpc.net/problem/21278
// Created by 윤혜경 on 2/9/24.

#include <bits/stdc++.h>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
bool visited[MAX] = { false, };

int dfs(int x, int y, int cnt) {
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        int nx = graph[x][i];
        if (visited[nx])
            continue;
        if (nx == y)
            break;
        cnt += dfs(nx, y, cnt + 1);
    }
    return cnt;
}

int main() {
    int N, M;
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int cnt = 100000;
    pair<int, int> res = {0, 0};
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int time = dfs(i, j, 0);
            if (time <= cnt) {
                if (res.first > i || res.second > j) {
                    res.first = i;
                    res.first = j;
                }
                cnt = time;
            }
            memset(visited, false, sizeof(visited));
        }
    }
    cout << res.first << ' ' << res.second << ' ' << cnt;
}