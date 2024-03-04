// BOJ 2580 스도쿠 https://www.acmicpc.net/problem/2580
// Created by 윤혜경 on 3/4/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int sudoku[9][9];
bool isEnd;

bool rule(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[x][i] == n)
            return false;
        if (sudoku[i][y] == n)
            return false;
        if (sudoku[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3] == n)
            return false;
    }
    return true;
}

void backtracking(int x, int y) {
    if (isEnd)
        return;

    if (x == 9) {
        isEnd = true;

        for (auto & i : sudoku) {
            for (int j : i)
                cout << j << ' ';
            cout << '\n';
        }

        return;
    }

    int nx, ny;
    if (y + 1 == 9) {
        nx = x + 1;
        ny = 0;
    } else {
        nx = x;
        ny = y + 1;
    }

    if (sudoku[x][y])
        backtracking(nx, ny);
    else {
        for (int i = 1; i < 10; i++) {
            if (!rule(x, y, i))
                continue;

            sudoku[x][y] = i;
            backtracking(nx, ny);
            sudoku[x][y] = 0;
        }
    }
}

int main() {
    fastio;

    for (auto & i : sudoku)
        for (int & j : i)
            cin >> j;

    backtracking(0, 0);
}