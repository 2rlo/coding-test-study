//
// Created by 윤혜경 on 1/23/24.
//
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int res = 0;
int input[MAX];
vector<int> tree[MAX];
bool visited[50] = {false, };

void dfs(int x) {
    visited[x] = true;

    int len = tree[x].size();
    if (!len)
        res++;

    for (int i = 0; i < len; i++) {
        int y = tree[x][i];
        if (!visited[y])
            dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, del;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    cin >> del;

    int root;
    for (int i = 0; i < N; i++) {
        if (input[i] == -1) {
            if (del == i) {
                cout << 0;
                return 0;
            }
            root = i;
            continue;
        }
        if (i == del)
            continue;
        tree[input[i]].push_back(i);
    }

    dfs(root);

    cout << res;
    return 0;
}