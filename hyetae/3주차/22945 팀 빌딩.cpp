//
// Created by 윤혜경 on 1/17/24.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int maxi = 0;
    int pt1 = 0, pt2 = N - 1;
    while (pt1 < pt2) {
        maxi = max(maxi, (pt2 - pt1 - 1) * min(v[pt1], v[pt2]));

        if (v[pt1] < v[pt2])
            pt1++;
        else
            pt2--;
    }

    cout << maxi;

    return 0;
}