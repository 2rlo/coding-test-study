//
// Created by 윤혜경 on 1/22/24.
//
#include <bits/stdc++.h>
using namespace std;

struct circle {
    int val, is_open, idx;
};

bool cmp(circle a, circle b) {
    return a.val < b.val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int x, r;
    vector<circle> v;
    for (int i = 0; i < N; i++) {
        cin >> x >> r;
        v.push_back({x - r, 1, i});
        v.push_back({x + r, 0, i});
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> st;
    string res = "YES";
    for (circle c: v) {
        if (c.is_open == 1) {
            st.push_back(c.idx);
        } else {
            if (c.idx == st.back()) {
                st.pop_back();
            } else {
                res = "NO";
                break;
            }
        }
    }

    cout << res;

    return 0;
}