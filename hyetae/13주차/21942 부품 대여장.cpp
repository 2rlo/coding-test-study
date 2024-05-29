// BOJ 21942 부품 대여장 https://www.acmicpc.net/problem/21942
// Created by 윤혜경 on 4/11/24.

#include "bits/stdc++.h"
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int N, F, due;
string L, d, t, p, m;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<string, vector<pair<int, string>>> note;
map<string, long long> fee;

int main() {
    fastio;
    cin >> N >> L >> F;

    due += stoi(L.substr(0, 3)) * 24 * 60;
    due += stoi(L.substr(4, 2)) * 60 + stoi(L.substr(7, 2));

    while (N--) {
        cin >> d >> t >> p >> m;

        int tt = 0;
        for (int i = 0; i < stoi(d.substr(5, 2)); i++)
            tt += month[i];
        tt += (stoi(d.substr(8, 2)) - 1);
        tt *=  24 * 60;
        tt += stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));

        int flag = 1;
        for (auto i = note[m]. begin(); i != note[m].end(); i++) {
            if (i->second == p) {
                long long f = tt - i->first - due;
                if (f > 0)
                    fee[m] += f * F;
                note[m].erase(i);
                flag = 0;
                break;
            }
        }

        if (flag)
            note[m].push_back({tt, p});
    }

    if (fee.empty())
        cout << -1;
    else
        for (auto f: fee)
            if (f.second > 0)
                cout << f.first << ' ' << f.second << '\n';

    return 0;
}