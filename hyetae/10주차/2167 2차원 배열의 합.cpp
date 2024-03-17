// BOJ 2167 2차원 배열의 합 https://www.acmicpc.net/problem/2167
// Created by 윤혜경 on 3/12/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, M, K;
int i, j, x, y;
int arr[301][301];

int main() {
    fastio;
    memset(arr, 0, sizeof(arr));
    cin >> N >> M;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= M; b++) {
            cin >> arr[a][b];
            arr[a][b] += arr[a][b - 1] + arr[a - 1][b] - arr[a - 1][b - 1];
        }
    }

    cin >> K;
    for (int a = 0; a < K; a++) {
        cin >> i >> j >> x >> y;
        cout << arr[x][y] - arr[i - 1][y] - arr[x][j - 1] + arr[i - 1][j - 1]<< '\n';
    }
}