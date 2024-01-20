// BOJ 22945 팀 빌딩 https://www.acmicpc.net/problem/22945
// Created by JEY on 2024-01-21.

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int stats[MAX];

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> stats[i];
    }

    int start = 0, end = n-1;
    int ans = 0;

    while (start <= end) {
        ans = max(ans, (end - start - 1) * min(stats[start], stats[end]));

        if (stats[end] > stats[start])
            start++;
        else
            end--;
    }

    cout << ans;

    return 0;
}
