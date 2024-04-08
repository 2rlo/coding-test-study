// BOJ 1976 여행 가자
// https://www.acmicpc.net/problem/1976

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;      // n < 200, m < 1000
int con[201];

int find(int x){
    if(con[x] == x) return x;
    return con[x] = find(con[x]);
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x < y) con[y] = x;
    else con[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        con[i] = i;

    int tmp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
        cin >> tmp;
        if(tmp == 1)
            uni(i, j);
        }
    }

    int root;
    for(int i=0; i<m; i++){
        cin >> tmp;
        if(i==0) root = find(tmp);
        else {
            if(find(root) != find(tmp)){
                cout << "NO";
                return 0;
            }
        }
    }
    
    cout << "YES";

    return 0;
}