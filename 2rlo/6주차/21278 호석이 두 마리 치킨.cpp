// BOJ 21278 호석이 두 마리 치킨 https://www.acmicpc.net/problem/21278

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int ch1 = 0, ch2= 0;
    cin >> n >> m;

    int ab[101][101];
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(i==j) ab[i][j] = 0;
            else ab[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        ab[a][b] = 1;
        ab[b][a] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int a = 1; a<=n; a++){
            for(int b = 1; b<=n; b++){
                ab[a][b] = min(ab[a][b], ab[a][i] + ab[i][b]);
            }
        }
    }

    int mini = 100001;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int temp = 0;
            for(int k = 1; k<=n; k++){
                temp += min(i==k ? 0 : ab[i][k], j==k?0:ab[i][k]);
            }
            if(temp < mini){
                mini = temp;
                ch1 = i;
                ch2 = j;
            }
        }
    }

    cout << ch1 << ' ' << ch2 << ' ' << mini*2;

    return 0;
}