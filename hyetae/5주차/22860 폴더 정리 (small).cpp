// BOJ 22860 폴더 정리 (small)  https://www.acmicpc.net/problem/22860
// Created by 윤혜경 on 2/19/24.

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1001
using namespace std;

int cnt = 0;
int N, M, C, Q;
string P, F, q;
map<string, vector<pair<string, int>>> tree;
set<string> s;

void dfs(string target, string now) {
    for (int i = 0; i < tree[now].size(); i++) {
        if (!tree[now][i].second) {
            s.insert(tree[now][i].first);
            cnt++;
        } else dfs(target, tree[now][i].first);
    }

    if (target != now)
        return;

    cout << s.size() << ' ' << cnt << '\n';
    cnt = 0;
    s.clear();
    return;
}

string parser(string q) {
    string name = "";
    for (char c: q) {
        if (c == '/')
            name = "";
        else
            name += c;
    }
    return name;
}

int main() {
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        cin >> P >> F >> C;
        if (tree.find(P) == tree.end()) {
            vector<pair<string, int>> v;
            v.push_back({F, C});
            tree[P] = v;
        } else {
            tree[P].push_back({F, C});
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> q;
        string target = parser(q);
        dfs(target, target);
    }

    return 0;
}