// BOJ 16987 계란으로 계란치기  https://www.acmicpc.net/problem/16987
// Created by 윤혜경 on 3/5/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N;
int egg[8][8];
int broken[8] = { 0, };
int maxi = -1e9;

void backtracking(int hand) {
    if (hand == N) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (egg[i][0] < 1)
                cnt++;
        maxi = max(maxi, cnt);
        return;
    }

    if (egg[hand][0] < 1)
        backtracking(hand + 1);
    else {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (i == hand || egg[i][0] < 1)
                continue;

            egg[i][0] -= egg[hand][1];
            egg[hand][0] -= egg[i][1];
            flag = false;
            backtracking(hand + 1);
            egg[i][0] += egg[hand][1];
            egg[hand][0] += egg[i][1];
        }

        if (flag)
            backtracking(N);
    }
}

int main() {
    fastio;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> egg[i][0] >> egg[i][1];

    backtracking(0);
    cout << maxi;
}
