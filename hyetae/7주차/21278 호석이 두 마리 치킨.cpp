// BOJ 21278 호석이 두 마리 치킨 https://www.acmicpc.net/problem/21278
// Created by 윤혜경 on 2/9/24.

#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio(0)
#define MAX 101
using namespace std;

int main() {
    fastio;

    int graph[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph[i][j] = (i == j) ? 0 : 1e9;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for (int i = 1; i <= N; i++)
        for (int a = 1; a <= N; a++)
            for (int b = 1; b <= N; b++)
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);

    int mini = 1e9;
    int chicken1 = 0, chicken2 = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int tmp = 0;
            for (int k = 1; k <= N; k++)
                tmp += min(i == k ? 0 : graph[i][k], j == k ? 0 : graph[j][k]);

            if (tmp < mini) {
                mini = tmp;
                chicken1 = i;
                chicken2 = j;
            }
        }
    }
    cout << chicken1 << ' ' << chicken2 << ' ' << mini * 2;
}