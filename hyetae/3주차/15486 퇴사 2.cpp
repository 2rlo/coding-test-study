//
// Created by 윤혜경 on 1/17/24.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int res = 0;
    int maxi = 0;
    vector<int> dp(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int time, point;
        cin >> time >> point;

        maxi = max(maxi, dp[i]);

        int end = i + time;
        if (i + time <= N) {
            dp[end] = max(dp[end], maxi + point);
            res = max(res, dp[end]);
        }
    }
    cout << res;
    return 0;
}