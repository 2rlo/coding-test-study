// BOJ 11265 끝나지 않는 파티
// https://www.acmicpc.net/problem/11265

#include <iostream>
#include <vector>
using namespace std;

int n, m;    // size, num
int dist[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            {
                cin >> dist[i][j];
            }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(dist[j][i] + dist[i][k] < dist[j][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;

        if(dist[a][b] <= c){
            cout << "Enjoy other party\n";
        }
        else {
            cout << "Stay here\n";
        }
    }

    return 0;
}