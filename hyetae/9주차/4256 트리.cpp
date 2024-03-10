// BOJ 4256 트리 https://www.acmicpc.net/problem/4256
// Created by 윤혜경 on 2/28/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int T, n;
int pre[1'000], in[1'000];

void post(int start, int end, int idx) {
    for (int i = start; i < end; i++) {
        if (pre[idx] == in[i]) {
            post(start, i, idx + 1);
            post(i + 1, end, idx + 1 + i - start);
            cout << pre[idx] << ' ';
        }
    }
}

int main() {
    fastio;

    cin >> T;
    while(T--) {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> pre[i];
        for (int i = 0; i < n; i++)
            cin >> in[i];

        post(0, n, 0);
        cout << '\n';
    }
}