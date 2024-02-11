// BOJ 16637 괄호 추가하기 https://www.acmicpc.net/problem/16637
// Created by JEY on 2024-02-11.

#include <iostream>
#include <algorithm>
using namespace std;

int n, res = -1e9;
string str;

int cal (int a, int b, char op){
    switch (op) {
        case '+':
            a+=b;
            break;
        case '-':
            a-=b;
            break;
        case '*':
            a *= b;
            break;
    }

    return a;
}

void dfs(int idx, int cur){
    if(idx >= n){
        res = max(res, cur);
        return;
    }
    char op = idx == 0 ? '+' : str[idx-1];

    if(idx + 2 < n){
        int bracket = cal(str[idx]-'0', str[idx+2]-'0', str[idx+1]);
        dfs(idx+4, cal(cur, bracket, op));
    }

    dfs(idx+2, cal(cur, str[idx]-'0', op));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> str;

    dfs(0, 0);
    cout << res;

    return 0;
}
