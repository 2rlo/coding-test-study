// BOJ 2285 우체국 https://www.acmicpc.net/problem/2285
// Created by JEY on 2024-01-10.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans;
    long long all = 0;
    cin >> n;

    vector<pair<int, int>> v;
    int i=0;
    for(; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        all += b;
    }

    long long until = 0;
    sort(v.begin(), v.end());
    for(int i=0; i<(int)v.size(); i++){
        until += v[i].second;
        double half = all / 2.0;
        if(until >= half){
            ans = i;
            break;
        }
    }

    cout << v[ans].first;

    return 0;
}