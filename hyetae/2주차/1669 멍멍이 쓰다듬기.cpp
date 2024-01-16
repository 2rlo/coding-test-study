#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, Y;
    cin >> X >> Y;

    long long diff = Y - X;
    if (diff < 4) {
        cout << diff;
        return 0;
    }

    long long cnt = 1;
    while (cnt * cnt < diff)
        cnt++;

    if (cnt * cnt == diff) {
        cout << cnt * 2 - 1;
        return 0;
    }

    if (diff - (cnt - 1) * (cnt - 1) <= (cnt - 1))
        cout << cnt * 2 - 2;
    else
        cout << cnt * 2 - 1;

    return 0;
}