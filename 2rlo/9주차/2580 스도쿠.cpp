// BOJ 2580 스도쿠 https://www.acmicpc.net/problem/2580

#include <iostream>
#include <vector>

using namespace std;

int sdoku[9][9] = {0,};
vector<pair<int, int>> blank;
int zero = 0;
bool flag = false;

bool check(pair<int, int> p) {
    int square_x = p.first / 3;
    int square_y = p.second / 3;

    for (int i = 0; i < 9; i++) {
        if (sdoku[p.first][i] == sdoku[p.first][p.second] && i != p.second)
            return false;
        if (sdoku[i][p.second] == sdoku[p.first][p.second] && i != p.first)
            return false;
    }

    for (int i = 3 * square_x; i < 3 * square_x + 3; i++) {
        for (int j = 3 * square_y; j < 3 * square_y + 3; j++) {
            if (sdoku[i][j] == sdoku[p.first][p.second]) {
                if (i != p.first && j != p.second)
                    return false;
            }
        }
    }

    return true;
}

void ans(int n) {
    if (zero == n) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sdoku[i][j] << " ";
            }
            cout << "\n";
        }
        flag = true;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        sdoku[blank[n].first][blank[n].second] = i;
        if (check(blank[n]))
            ans(n + 1);
        if (flag)
            return;
    }

    sdoku[blank[n].first][blank[n].second] = 0;
    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> b;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[i][j];
            if (sdoku[i][j] == 0) {
                zero++;
                b.first = i;
                b.second = j;
                blank.push_back(b);
            }
        }
    }

    ans(0);

    return 0;
}