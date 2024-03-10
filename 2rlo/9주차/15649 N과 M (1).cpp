// BOJ 15649 N과 M (1) https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void backtracking(int len) {
    if (len == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[len] = i;
            backtracking(len + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    backtracking(0);

    return 0;
}