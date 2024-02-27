// BOJ 2110 공유기 설치 https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 100001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 공유기 개수 c, 집의 개수 n
    int n, c;
    cin >> n >> c;

    // 집의 좌표 x_i;
    vector<int> x;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }

    sort(x.begin(), x.end());

    int min = 1, max = x[n-1]+1;
    while(min < max){
        int mid = (min+max) / 2;
        int cnt = 1;
        int prev = x[0];
        for(int i=1; i<n; i++){
            int cur = x[i];
            if(cur - prev < mid)
                continue;
            prev = cur;
            cnt++;
        }
        if(cnt < c){
            max = mid;
        }
        else {
            min = mid+1;
        }
    }

    // 가장 인접한 공유기 사이의 거리를 최대로 할 때의 거리 출력
    cout << max -1;

    return 0;
}