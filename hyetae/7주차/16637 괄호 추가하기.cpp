// BOJ 16637 괄호 추가하기 https://www.acmicpc.net/problem/16637
// Created by 윤혜경 on 2/9/24.
#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, res = -1e9;
string input;

int cal(int a, int b, char op) {
    switch (op) {
        case '+':
            return a += b;
        case '-':
            return a -= b;
        case '*':
            return a *= b;
    }
    return 0;
}

void dfs(int idx, int num) {
    if (idx >= N) {
        res = max(res, num);
        return;
    }

    char op = (idx == 0) ? '+' : input[idx - 1];

    if (N > idx + 2) {
        int bracket = cal(input[idx] - '0', input[idx + 2] - '0', input[idx + 1]);
        dfs(idx + 4, cal(num, bracket, op));
    }

    dfs(idx + 2, cal(num, input[idx] - '0', op));
}

int main() {
    fastio;
    cin >> N >> input;
    dfs(0, 0);
    cout << res;
}