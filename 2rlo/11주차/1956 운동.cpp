// BOJ 1956 운동
// https://www.acmicpc.net/problem/1956

#include <iostream>
#include <vector>
using namespace std;

int v, e;
int arr[401][401];
int ans = 4000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            arr[i][j] = ans;
        }
    }

    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i=1; i<=v; i++){
        ans = min(ans, arr[i][i]);
    }

    if(ans == 4000001)
        cout << "-1";
    else 
        cout << ans;

    return 0;
}