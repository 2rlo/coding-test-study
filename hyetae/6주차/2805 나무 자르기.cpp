// BOJ 2805 나무 자르기 https://www.acmicpc.net/problem/2805
// Created by 윤혜경 on 2/13/24.

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int N, M, wood[1'000'000];

int binary_search(int mid) {
    long long sum = 0;
    for (int i = 0; i < N; i++)
        if (wood[i] > mid)
            sum += wood[i] - mid;
    return sum >= M;
}

int main() {
    fastio;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> wood[i];

    int lo = 0, hi = 1e9;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (binary_search(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo;
    return 0;
}