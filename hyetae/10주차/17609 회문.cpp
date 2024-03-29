// BOJ 17609 회문 https://www.acmicpc.net/problem/17609
// Created by 윤혜경 on 3/29/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int sol(string str, int check) {
    int left = 0;
    int right = str.size() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            if (!check) {
                int len = right - left;
                if (!sol(str.substr(left + 1, len), 1)
                    || !sol(str.substr(left, len), 1))
                    return 1;
                else return 2;
            } else return 2;
        }
        left++;
        right--;
    }
    return 0;
}

int main() {
    fastio;
    int N;
    cin >> N;

    while(N--) {
        string input;
        cin >> input;
        cout << sol(input, 0) << '\n';
    }
}