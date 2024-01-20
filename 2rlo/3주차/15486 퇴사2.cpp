// BOJ 15486 퇴사2 https://www.acmicpc.net/problem/15486
// Created by JEY on 2024-01-21.

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1500001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int dp[MAX];
    int arr[MAX][2];

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    int ans = 0;
    for(int i=1; i<=n+1; i++){
        ans = max(ans, dp[i]);
        if(i + arr[i][0] > n+1) continue;
        dp[i+arr[i][0]] = max(ans + arr[i][1], dp[i + arr[i][0]]);
    }

    cout << ans;

    return 0;
}