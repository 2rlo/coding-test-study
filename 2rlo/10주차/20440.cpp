// BOJ 20440 🎵니가 싫어 싫어 너무 싫어 싫어 오지 마 내게 찝쩍대지마🎵 -1
// https://www.acmicpc.net/problem/20440

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> stay;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    unordered_map<int, int> m;
    int ent, exit;
    for(int i=0; i<n; i++){
        cin >> ent >> exit;
        if(m.count(ent)) ++m[ent];
        else m[ent] = 1;
        if(m.count(exit)) --m[exit];
        else m[exit] = -1;
    }

    stay.assign(m.begin(), m.end());
    sort(stay.begin(), stay.end());

    int ans = 0, cur = 0, end = -1, st = 0;

    for(int i=0; i<stay.size(); i++){
        cur += stay[i].second;
        if (cur > ans){
            ans = cur;
            st = stay[i].first;
            end = -1;
        }
        else if (cur < ans){
            if(end == -1)
                end = stay[i].first;
        }
    }

    cout << ans << "\n" << st << ' ' << end;

    return 0;
}