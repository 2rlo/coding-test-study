// BOJ 18430 무기 공학 https://www.acmicpc.net/problem/18430

#include <iostream>
#include <vector>

using namespace std;

int n, m;   // 가로, 세로
int k[5][5];    // 강도
bool visited[5][5];
vector<pair<int, int>> boo[4] = {{{-1, 0},  {0, 1}},
                                 {{-1, 0},  {0, -1}},
                                 {{0,  -1}, {1, 0}},
                                 {{0,  1},  {1, 0}}};
int res = 0;

void ans(int x, int y, int sum) {
    res = max(res, sum);

    if (y == m) {
        y = 0;
        x++;
    }

    if (x == n) return;
    if (!visited[x][y]) {
        for (int i = 0; i < 4; i++) {
            int nx1 = x + boo[i][0].first;
            int ny1 = y + boo[i][0].second;
            int nx2 = x + boo[i][1].first;
            int ny2 = y + boo[i][1].second;

            if (nx1 >= 0 && nx2 >= 0 && nx1 < n && nx2 < n && ny1 >= 0 && ny2 >= 0 && ny1 < m && ny2 < m) {
                if (visited[nx1][ny1] || visited[nx2][ny2]) continue;
                visited[nx1][ny1] = true;
                visited[nx2][ny2] = true;
                visited[x][y] = true;

                ans(x, y + 1, sum + (k[x][y] * 2) + k[nx1][ny1] + k[nx2][ny2]);

                visited[nx1][ny1] = false;
                visited[nx2][ny2] = false;
                visited[x][y] = false;
            }
        }
    }

    ans(x, y + 1, sum);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> k[i][j];
        }
    }

    ans(0, 0, 0);
    cout << res;
    return 0;
}