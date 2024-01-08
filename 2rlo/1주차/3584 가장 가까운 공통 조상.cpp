// BOJ 3584 가장 가까운 공통 조상 https://www.acmicpc.net/problem/3584
// LCA(Lowest Common Ancestor) 문제

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 100001

int n;
int depth[MAX], parent[MAX];
vector<int> children[MAX];

void dfs(int curr) {
    for(auto child: children[curr]){
        depth[child] = depth[curr] + 1;
        dfs(child);
    }
}

int NCA(int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);

    while(depth[a] > depth[b]) {
        a = parent[a];
    }

    while ( a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

void initTestcase() {
    for(int i=0; i<MAX; i++){
        children[i].clear();
        parent[i] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        initTestcase();
        cin >> n;
        int a, b;
        for(int i=0; i<n-1; i++){
            cin >> a >> b ;
            children[a].push_back(b);
            parent[b] = a;
        }
        for(int i=1; i<=n; i++){
            if(parent[i] == i) {
                depth[i] = 0;
                dfs(i);
                break;
            }
        }

        cin >> a >> b;
        cout << NCA(a, b) << "\n";
    }
    
    return 0;
}