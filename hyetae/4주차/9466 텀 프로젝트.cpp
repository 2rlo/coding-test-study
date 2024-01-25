// BOJ 9466 텀 프로젝트 https://www.acmicpc.net/problem/9466
// Created by 윤혜경 on 1/25/24.

#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int res;
vector<int> v, graph[MAX];
bool visited[MAX] = { false, };

void dfs(int x) {
    visited[x] = true;
    v.push_back(x);

    for (int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i];

        if (v.front() == y) {
            while (!v.empty()) {
                res++;
                v.pop_back();
            }
            break;
        }

        if (!visited[y])
            dfs(y);
    }

    if (v.size())
        v.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        res = 0;
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));

        int N;
        cin >> N;

        int input;
        for (int i = 1; i <= N; i++) {
            cin >> input;
            graph[input].push_back(i);
        }

        for (int i = 1; i <= N; i++)
            if (!visited[i])
                dfs(i);

        cout << N - res << "\n";
    }


    return 0;
};