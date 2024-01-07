#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int parent[MAX] = { 0 ,};

vector<int> bfs (int x) {
    vector<int> parents;
    parents.push_back(x);

    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        int y = parent[a];
        if (y) {
            parents.push_back(y);
            q.push(y);
        }
    }

    return parents;
}

int main() {
    int T, N, x, y;
    vector<int> parents1, parents2;

    cin >> T;
    while (T--) {
        cin >> N;

        for (int i = 0; i < N - 1; i++) {
            cin >> x >> y;
            parent[y] = x;
        }

        cin >> x >> y;
        parents1 = bfs(x);
        parents2 = bfs(y);

        int br = 0;
        for (int i: parents1) {
            if (br)
                break;
            for (int j: parents2) {
                if (i == j) {
                    cout << i << "\n";
                    br = 1;
                    break;
                }
            }
        }

        memset(parent, 0, MAX);
    }

    return 0;
}