// BOJ 1669 멍멍이 쓰다듬기 https://www.acmicpc.net/problem/1669
// Created by JEY on 2024-01-10.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int n = y - x;

    if(n == 0){
      cout << 0;
      return 0;
    }
    else if (sqrt(n)-(int)sqrt(n) == 0 ){
        cout << 2*sqrt(n) - 1;
        return 0;
    }
    else {
        if(n-(pow((int)sqrt(n), 2)) <= sqrt(n)){
            cout << 2*(int)sqrt(n);
            return 0;
        }
        else {
            cout << 2*(int)sqrt(n)+1;
            return 0;
        }
    }
}