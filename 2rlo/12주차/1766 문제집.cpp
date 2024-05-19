// BOJ 1766 문제집
// https://www.acmicpc.net/problem/1766

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int done[32001] = {0,};
    vector<int> seq[32001];
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        done[b]++;
        seq[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        if(done[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()){
        int problem = pq.top();
        pq.pop();

        cout << problem<<" ";

        for(int i=0; i<seq[problem].size(); i++){
            int next = seq[problem][i];
            done[next]--;
            if(done[next]==0)
                pq.push(next);
        }
    }

    cout << "\n";
    
    return 0;
}