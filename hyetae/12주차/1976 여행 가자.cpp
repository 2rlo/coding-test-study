#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, M;
int plan[1'000];
int graph[201][201];

int main() {
    fastio;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> graph[i][j];

    for (int i = 1; i <= N; i++)
        graph[i][i] = 1;

    for (int i = 0; i < M; i++)
        cin >> plan[i];

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (!graph[i][j] && graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }

    for (int i = 0; i < M - 1; i++)
        if (!graph[plan[i]][plan[i + 1]]) {
            cout << "NO";
            return 0;
        }

    cout << "YES";
    return 0;
}
