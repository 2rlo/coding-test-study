// BOJ 11265 끝나지 않는 파티 https://www.acmicpc.net/problem/11265
// Created by 윤혜경 on 2/4/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, M;
int A, B, C;
int graph[501][501];

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> graph[i][j];

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    while (M--) {
        cin >> A >> B >> C;
        if (graph[A][B] <= C)
            cout << "Enjoy other party" << '\n';
        else
            cout << "Stay here" << '\n';
    }

    return 0;
}