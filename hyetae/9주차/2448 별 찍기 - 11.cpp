// BOJ 2448 별 찍기 - 11 https://www.acmicpc.net/problem/2448
// Created by 윤혜경 on 2/28/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
#define MAX 3072
using namespace std;

char star[MAX][MAX * 2 - 1];

void solve(int n, int x, int y) {
    if (n == 3) {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';
        for (int i = 0; i < 5; i++)
            star[x + 2][y - 2 + i] = '*';
    } else {
        solve(n / 2, x, y);
        solve(n / 2, x + n / 2, y - n / 2);
        solve(n / 2, x + n / 2, y + n / 2);
    }
}

int main() {
    fastio;

    int N;
    cin >> N;

    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N * 2 - 1; j++)
            star[i][j] = ' ';

    solve(N, 0, N - 1);

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N * 2 - 1; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }
}