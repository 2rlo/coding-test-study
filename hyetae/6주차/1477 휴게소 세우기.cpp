// BOJ 1477 휴게소 세우기 https://www.acmicpc.net/problem/1477
// Created by 윤혜경 on 2/13/24.

#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, M, L, rest[52];

int main() {
    fastio;
    cin >> N >> M >> L;

    rest[0] = 0, rest[N + 1] = L;
    for (int i = 1; i < N + 1; i++)
        cin >> rest[i];

    sort(rest, rest + N + 2);

    int res = 1e9;
    int lo = 1, hi = L - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int num = 0;

        for (int i = 1; i < N + 2; i++) {
            int dist = rest[i] - rest[i - 1];
            int cnt = dist / mid;

            if (cnt > 0) {
                if (dist % mid == 0)
                    num += cnt - 1;
                else
                    num += cnt;
            }
        }

        if (num > M)
            lo = mid + 1;
        else {
            hi = mid - 1;
            res = min(res, mid);
        }
    }
    cout << res;
}