// BOJ 20437 문자열 게임 2
// https://www.acmicpc.net/problem/20437

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    vector<int> alphabet(26);

    while(t--){
        int minValue = 10001, maxValue = 0;
        string w;
        int k, cnt;

        cin >> w >> k;
        
        for(int i=0; i<w.length(); i++)
            ++alphabet[w[i]-'a'];

        for(int i=0; i<w.length(); i++){
            if(alphabet[w[i]-'a'] < k)
                continue;

            cnt = 0;
            for(int j = i; j<w.length(); j++){
                if(w[i] == w[j])
                    cnt++;
                
                if(cnt == k){
                    minValue = min(minValue, j-i+1);
                    maxValue = max(maxValue, j-i+1);
                    break;
                }
            }
        }
        if(minValue == 10001 || maxValue == 0){
            cout << -1 << "\n";
        }
        else {
            cout << minValue << " " << maxValue << "\n";
        }
    } 

    return 0;
}