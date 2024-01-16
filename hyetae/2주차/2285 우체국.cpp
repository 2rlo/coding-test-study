#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int maxi = 0;
    vector<long long> x(N);
    vector<long long> y(N);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    int m;
    int l = -1e9, r = 1e9;
    while (l <= r) {
        m = (l + r) / 2;
        long long a = 0, b = 0;
        for (int i = 0; i < N; i++) {
            a += abs(x[i] - m) * y[i];
            b += abs(x[i] - (m + 1)) * y[i];
        }

        if (a <= b)
            r = m - 1;
        else
            l = m + 1;
    }

    cout << l;
}