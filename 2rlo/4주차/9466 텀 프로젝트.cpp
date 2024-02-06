// BOJ 9466 텀 프로젝트 https://www.acmicpc.net/problem/9466
// Created by JEY on 2024-01-27.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100001
int people = 0;
int sel[MAX];
bool visited[MAX];
bool cycle[MAX];

void dfs(int node){
    visited[node] = true;
    int next = sel[node];

    if(!visited[next]){
        dfs(next);
    }
    else if (!cycle[next]){
        for(int i=next; i!=node; i=sel[i]){
            people++;
        }
        people++;
    }
    cycle[node] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            cin >> sel[i];
        }
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        cout << n - people << "\n";

        people = 0;
        memset(visited, false, sizeof(visited));
        memset(cycle, false, sizeof(cycle));
    }
    return 0;
}