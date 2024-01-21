// BOJ 15961 회전 초밥 https://www.acmicpc.net/problem/15961
// Created by JEY on 2024-01-21.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c;
    vector<int> dish;
    int cur_kind[3001] = { 0, };

    cin >> n >> d >> k >> c;

    int start = 0, end = k-1;
    cur_kind[c] = 1;
    int kind = 1;

    for(int i=0; i<n; i++){
        int x = 0;
        cin >> x;
        dish.push_back(x);
        if(i<k) {
            cur_kind[x]++;
            if (cur_kind[x] == 1) kind++;
        }
    }

    for(int i=0; i<k; i++){
        dish.push_back(dish[i]);
    }

    int ans = 0;

    while(1){
        ans = max(ans, kind);
        if(start == n) break;
        cur_kind[dish[start]]--;
        if(cur_kind[dish[start++]] == 0) kind--;
        cur_kind[dish[++end]]++;
        if(cur_kind[dish[end]]==1) kind++;
    }

    cout << ans;

    return 0;
}
