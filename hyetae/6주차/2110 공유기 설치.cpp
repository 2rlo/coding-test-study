// BOJ 2110 공유기 설치 https://www.acmicpc.net/problem/2110
// Created by 윤혜경 on 2/13/24.

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    int N, C;
    cin >> N >> C;

    int router[200'000];
    for (int i = 0; i < N; i++)
        cin >> router[i];

    sort(router, router + N - 1);

    int res = 0;
    int lo = 1, hi = router[N - 1] - router[0];
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int cnt = 1;
        int pre = router[0];

        for (int i = 1; i < N; i++) {
            if (router[i] - pre >= mid) {
                cnt++;
                pre = router[i];
            }
        }

        if (cnt >= C) {
            res = max(res, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << res;
    return 0;
}