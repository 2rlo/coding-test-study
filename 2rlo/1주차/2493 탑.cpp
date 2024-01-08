// BOJ 2493 탑 https://www.acmicpc.net/problem/2493

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp;
    stack<pair<int, int>> tower;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> temp;
        while(!tower.empty()){
            if(tower.top().first>=temp){
                cout << tower.top().second << ' ';
                break;
            }
            tower.pop();
        }
        if(tower.empty()){
            cout << "0 ";
        }

        tower.push({temp, i});
    }

    return 0;
}