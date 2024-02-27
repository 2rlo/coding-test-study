// BOJ 1477 휴게소 세우기 https://www.acmicpc.net/problem/1477

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 휴게소 개수 n, 추가 휴게소 개수 m, 고속도로 길이 l
    int n, m, l, res = 1000;
    cin >> n >> m >> l;

    // 현재 휴게소 위치
    vector<int> n_loc;
    n_loc.push_back(0);
    n_loc.push_back(l);
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        n_loc.push_back(tmp);
    }

    sort(n_loc.begin(), n_loc.end());

    int cmin = 1, cmax = l - 1;
    while(cmin <= cmax){
        int mid = (cmin + cmax) / 2;
        int cnt = 0;

        for(int i=1; i<n_loc.size(); i++){
            int dis = n_loc[i] - n_loc[i-1];
            int ava = dis/mid;

            if(ava > 0){
                if(dis % mid == 0) cnt += ava - 1;
                else cnt += ava;
            }
        }

        if(cnt > m) cmin = mid + 1;
        else {
            cmax = mid - 1;
            res = min(mid, res);
        }
    }

    // 휴게소가 없는 구간의 최댓값의 최솟값
    cout << res;

    return 0;
}