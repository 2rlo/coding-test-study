// BOJ 14722 우유 도시 https://www.acmicpc.net/problem/14722
// Created by JEY on 2024-01-21.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int city[1000][1000], dp[1000][1000][3];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> city[i][j];
            if (city[i][j] == 0){
                dp[i][j][0] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == 0){
                dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
                dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1]);
                dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][2]);

                if(city[i][j] == 0){
                    if(dp[i][j-1][2] != 0)
                        dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][2] + 1);
                }
                else if (city[i][j] == 1){
                    if(dp[i][j-1][0] != 0)
                        dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0] + 1);
                }
                else {
                    if(dp[i][j-1][1] != 0 )
                        dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][1] + 1);
                }
            }
            else if (j == 0){
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1]);
                dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][2]);

                if(city[i][j] == 0){
                    if(dp[i-1][j][2] != 0)
                        dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][2] + 1);
                }
                else if (city[i][j] == 1){
                    if(dp[i-1][j][0] != 0)
                        dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] + 1);
                }
                else {
                    if(dp[i-1][j][1] != 0 )
                        dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][1] + 1);
                }
            }
            else {
                dp[i][j][0] = max(dp[i][j][0], max(dp[i-1][j][0], dp[i][j-1][0]));
                dp[i][j][1] = max(dp[i][j][1], max(dp[i-1][j][1], dp[i][j-1][1]));
                dp[i][j][2] = max(dp[i][j][2], max(dp[i-1][j][2], dp[i][j-1][2]));

                if(city[i][j] == 0){
                    if(dp[i-1][j][2] != 0)
                        dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][2] + 1);
                    if(dp[i][j-1][2] != 0)
                        dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][2]+1);
                }
                else if (city[i][j] == 1){
                    if(dp[i-1][j][0] != 0)
                        dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][0] + 1);
                    if(dp[i][j-1][0] != 0)
                        dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][0]+1);
                }
                else {
                    if(dp[i-1][j][1] != 0 )
                        dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][1] + 1);
                    if(dp[i][j-1][1] != 0)
                        dp[i][j][2] = max(dp[i][j][2], dp[i][j-1][1] +1);
                }
            }
        }
    }

    cout << max(dp[n-1][n-1][0], max(dp[n-1][n-1][1], dp[n-1][n-1][2]));

    return 0;
}