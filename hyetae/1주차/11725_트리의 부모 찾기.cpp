#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int res[MAX];
vector<int> graph[MAX];
int visited[MAX] = { 0, };

void bfs () {
    queue<int> q;
    visited[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                res[y] = x;
                visited[y] = 1;
                q.push(y);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int x , y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs();

    for (int i = 2; i <= N; i++)
        cout << res[i] << "\n";

    return 0;
}