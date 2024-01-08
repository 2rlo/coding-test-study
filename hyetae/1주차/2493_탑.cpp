#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int input;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        cin >> input;

        while (!v.empty()){
            if (v.back().second > input) {
                cout << v.back().first << ' ';
                break;
            }
            v.pop_back();
        }

        if (v.empty())
            cout << 0 << ' ';

        v.push_back({i + 1, input});
    }

    return 0;
}