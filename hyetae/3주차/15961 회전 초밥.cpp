//
// Created by 윤혜경 on 1/19/24.
//

#include <bits/stdc++.h>
using namespace std;

int num[3001] = { 0, };
int belt[3003000] = { 0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    int res = 0;
    for (int i = 0; i < N; i++)
        cin >> belt[i];
    for (int i = 0; i < k - 1; i++)
        belt[N + i] = belt[i];

    for (int i = 0; i < k; i++) {
        if (!num[belt[i]])
            res++;
        num[belt[i]]++;
    }

    if (!num[c])
        res++;
    num[c]++;

    int maxi = 0, pt = 0;
    while (pt < N) {
        num[belt[pt]]--;
        if (!num[belt[pt]])
            res--;
        if (!num[belt[pt + k]])
            res++;
        num[belt[pt + k]]++;
        maxi = max(maxi, res);
        pt++;
    }

    cout << maxi;
    return 0;
}