// BOJ 2448 별 찍기 - 11 https://www.acmicpc.net/problem/2448

#include <iostream>
using namespace std;

char ans[10001][10001];

void triangle(int len, int row, int col){
    if(len == 3){
        ans[row][col] = '*';
        
        ans[row+1][col-1] = '*';
        ans[row+1][col+1] = '*';

        for(int i=0; i<5; i++){
           ans[row+2][col-2+i] = '*'; 
        }

        return;
    }

    triangle(len/2, row, col);
    triangle(len/2, row+len/2, col-len/2);
    triangle(len/2, row+len/2, col+len/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++){
            ans[i][j] = ' ';
        }
    }

    triangle(n, 0, n-1);

    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++){
            cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}