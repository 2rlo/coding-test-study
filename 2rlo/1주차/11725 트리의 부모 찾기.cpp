// BOJ 11725 트리의 부모 찾기 https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int n;
int ans[MAX];
bool visit[MAX];
vector<int> tree[MAX];

void bfs(){
    queue<int> q;
    visit[1] = true;
    q.push(1);

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int i=0; i<tree[parent].size(); i++){
            int child = tree[parent][i];
            if(!visit[child]){
                ans[child] = parent;
                visit[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> n;
    
    for(int i=0; i<n; i++){    
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    bfs();

    for(int i=2; i<=n; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}