// BOJ 8980 택배 https://www.acmicpc.net/problem/8980
// Created by JEY on 2024-01-14.

#include <iostream>
#include <algorithm>
using namespace std;

struct del  {
    int sender;
    int reciever;
    int count;
};

bool cmp (del x, del y){
    if(x.reciever < y.reciever) return true;
    else if (x.reciever == y.reciever){
        if(x.sender < y.sender)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, m, cnt = 0, ans = 0;

    cin >> n >> c;
    cin >> m;

    del arr[m];
    int cap[100001] = {0,};

    for(int i=0; i<m; i++){
        cin >>  arr[i].sender >> arr[i].reciever >> arr[i].count;
    }

    sort(arr, arr+m, cmp);

    for(int i=0; i<m; i++){
        cnt = 0;

        for(int j=arr[i].sender; j <arr[i].reciever; j++) {
            cnt = max(cap[j], cnt);
        }

        int val = min(arr[i].count, c-cnt);
        ans += val;

        for(int j=arr[i].sender; j<arr[i].reciever; j++){
            cap[j] += val;
        }
    }

    cout << ans;

    return 0;
}