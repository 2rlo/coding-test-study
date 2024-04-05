// BOJ 1766 문제집 https://www.acmicpc.net/problem/1766
// Created by 윤혜경 on 4/2/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
#define MAX 32'001
using namespace std;

int N, M, A, B;
int visited[MAX];
vector<int> seq[MAX];
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    fastio;
    cin >> N >> M;
    memset(visited, 0, MAX);

    while (M--) {
        cin >> A >> B;
        visited[B]++;
        seq[A].push_back(B);
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i])
            pq.push(i);

    while (!pq.empty()) {
        int pb = pq.top();
        pq.pop();

        cout << pb << " ";

        for (int nx : seq[pb]) {
            visited[nx]--;
            if (!visited[nx])
                pq.push(nx);
        }
    }

    return 0;
}