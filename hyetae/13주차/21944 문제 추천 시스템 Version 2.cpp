// BOJ 21944 문제 추천 시스템 Version 2 https://www.acmicpc.net/problem/21944
// Created by 윤혜경 on 4/9/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, M;
int P, L, G, x;
// level, num
set<pair<int, int>> algo[101];
// num
set<int> level[101];
// level, algo
pair<int, int> problem[100'001];

void recommend(string cmd) {
    // G 알고리즘 중
    if (cmd == "recommend") {
        cin >> G >> x;
        // 제일 어려운 문제 중 문제 번호가 큰 것
        if (x == 1)
            cout << prev(algo[G].end())->second << '\n';
        // 제일 쉬운 문제 중 문제 번호가 작은 것
        else
            cout << algo[G].begin()->second << '\n';
        return;
    }
    if (cmd == "recommend2") {
        cin >> x;
        // 제일 어려운 문제 중 문제 번호가 큰 것
        if (x == 1) {
            for (int i = 100; i > 0; i--) {
                if (!level[i].empty()) {
                    cout << *prev(level[i].end()) << '\n';
                    break;
                }
            }
        }
        // 제일 쉬운 문제 중 문제 번호가 작은 것
        else {
            for (set<int> s: level) {
                if (!s.empty()) {
                    cout << *s.begin() << '\n';
                    break;
                }
            }
        }
        return;
    }
    // 난이도
    if (cmd == "recommend3") {
        int res = -1;
        cin >> x >> L;
        // L보다 크거나 같은 문제 중 가장 쉽고 문제 번호가 큰 것
        if (x == 1) {
            for (int i = L; i < 101; i++) {
                if (!level[i].empty()) {
                    res = *level[i].begin();
                    break;
                }
            }
        }
            // L보다 작은 문제 중 가장 어렵고 문제 번호가 작은 것
        else {
            for (int i = L - 1; i > 0; i--) {
                if (!level[i].empty()) {
                    res = *prev(level[i].end());
                    break;
                }
            }
        }
        cout << res << '\n';
        return;
    }
    return;
}

int main() {
    fastio;
    cin >> N;
    while (N--) {
        cin >> P >> L >> G;
        problem[P] = {L, G};
        level[L].insert(P);
        algo[G].insert({L, P});
    }

    cin >> M;
    string cmd;
    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> P >> L >> G;
            problem[P] = {L, G};
            level[L].insert(P);
            algo[G].insert({L, P});

        } else if (cmd == "solved") {
            cin >> P;
            int l = problem[P].first;
            int g = problem[P].second;
            level[l].erase(P);
            algo[g].erase({l, P});

        } else recommend(cmd);
    }
    return 0;
}