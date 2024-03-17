// BOJ 2015 수들의 합 4
// https://www.acmicpc.net/problem/2015

#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;

    cin >> n >> k;

    long long ans = 0;
    int a[20001];
    map<long long, long long> m;

    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        a[i] = a[i-1] + tmp;
    }

    for(int i=1; i<=n; i++){
        if(a[i] == k) ans++;
        ans += m[a[i]-k];
        m[a[i]]++;
    }

    cout << ans;

    return 0;
}