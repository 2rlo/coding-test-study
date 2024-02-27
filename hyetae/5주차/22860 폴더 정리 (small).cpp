// BOJ 22860 폴더 정리 (small)  https://www.acmicpc.net/problem/22860
// Created by 윤혜경 on 2/19/24.

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX 1001
using namespace std;
map<string, pair<int, int>> idx;
int graph[MAX][MAX] = { 0, };

pair<int, int> dfs(string goal){

}

int main() {
    fastio;

    int N, M;
    cin >> N >> M;

    int C, index = 0;
    string P, F;
    for (int i = 0; i < N + M; i++) {
        cin >> P >> F >> C;
        if (P == "main")
            idx[P] = make_pair(index++, 1);
        else if (!idx.count(P))
            idx[P] = make_pair(index++, C);
        else if (!idx.count(F))
            idx[F] = make_pair(index++, C);

        graph[idx[P].first][idx[F].first] = 1;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string input;
        cin >> input;
        string goal;
        for (char c: input) {
            if (isalpha(c))
                goal += c;
            else
                goal = "";
        }

        pair<int, int> res = dfs(goal);
        cout << res.first << ' ' << res.second << '\n';
    }



}