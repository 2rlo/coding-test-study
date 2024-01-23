//
// Created by 윤혜경 on 1/19/24.
//

#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int city[MAX][MAX] = { 0, };
int dp[MAX][MAX][3] = { 0, };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> city[i][j];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (city[i][j] == 0)
                dp[i][j][0] = max(dp[i - 1][j][2], dp[i][j - 1][2]) + 1;
            else
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);

            if (city[i][j] == 1 && dp[i][j][0] > dp[i][j][1])
                dp[i][j][1] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + 1;
            else
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]);

            if (city[i][j] == 2 && dp[i][j][1] > dp[i][j][2])
                dp[i][j][2] = max(dp[i - 1][j][1], dp[i][j - 1][1]) + 1;
            else
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i][j - 1][2]);
        }
    }

    cout << max(dp[N][N][0], max(dp[N][N][1], dp[N][N][2]));
    return 0;
}