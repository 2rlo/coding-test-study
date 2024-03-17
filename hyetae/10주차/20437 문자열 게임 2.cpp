// BOJ 20437 문자열 게임 2 https://www.acmicpc.net/problem/20437
// Created by 윤혜경 on 3/11/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int T, K;
string W;

void sol() {
    if (K == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    int maxi = -1e9;
    int mini = 1e9;
    map<char, int> cnt;
    map<char, queue<int>> idx;
    for (int i = 0; i < W.size(); i++) {
        char c = W[i];
        if (cnt[c]) {
            cnt[c]++;
            idx[c].push(i);
            if (cnt[c] == K) {
                maxi = max(maxi, i - idx[c].front() + 1);
                mini = min(mini, i - idx[c].front() + 1);
                idx[c].pop();
                cnt[c]--;
            }
        }
        else {
            cnt[c] = 1;
            queue<int> q;
            q.push(i);
            idx[c] = q;
        }
    }

    if (maxi == -1e9|| mini == 1e9)
        cout << -1 << '\n';
    else
        cout << mini << ' ' << maxi << '\n';
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> W >> K;
        sol();
    }
}