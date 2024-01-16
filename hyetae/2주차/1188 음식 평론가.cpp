#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int N, M;
    cin >> N >> M;

    cout << M - gcd(min(N, M), max(N, M));

    return 0;
}