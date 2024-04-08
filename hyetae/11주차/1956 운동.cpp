// BOJ 1956 운동 https://www.acmicpc.net/problem/1956
// Created by 윤혜경 on 3/29/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
#define MAX 40'100'000
using namespace std;

int V, E;
int a, b, c;
int graph[401][401];
int res = MAX;

int main() {
    fastio;
    cin >> V >> E;

    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            graph[i][j] = MAX;

    while (E--) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    for (int i = 1; i <= V; i++)
        res = min(res, graph[i][i]);

    cout << (res == MAX ? -1 : res);
    return 0;
}