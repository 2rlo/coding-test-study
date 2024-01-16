// BOJ 1188 음식 평론가 https://www.acmicpc.net/problem/1188
// Created by JEY on 2024-01-10.

#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if(x%y == 0)
        return y;
    return gcd(y, x%y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    cout << m - gcd(n, m);

    return 0;
}