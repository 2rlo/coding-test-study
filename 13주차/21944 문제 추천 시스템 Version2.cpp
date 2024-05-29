// BOJ 21944 문제 추천 시스템 Version2
// https://www.acmicpc.net/problem/21944

#include <iostream>
#include <string>
#include <set>
using namespace std;

int p_count;  // 문제 개수

int testcase;    // 명령문 개수
string command;     // 명령어

set<pair<int, int>> alg[101];
set<int> dif[101];
pair<int, int> problem[100001];

void input(){
    cin >> p_count;

    for(int i=0; i<p_count; i++){
        int num, d, a;
        cin >> num >> d >> a;
        alg[a].insert(make_pair(d, num));
        dif[d].insert(num);
        problem[num] = make_pair(d, a);
    }

    cin >> testcase;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    int var1, var2, var3;

    while(testcase--){
        cin >> command;
        if(command == "recommend"){
            cin >> var1 >> var2;
            if(var2 == 1){
                auto temp = *prev(alg[var1].end());
                cout << temp.second << "\n";
            }
            else {
                auto temp = *alg[var1].begin();
                cout << temp.second << "\n";
            }      
        }
        else if (command == "recommend2"){
            cin >> var1;
            if(var1 == 1){
                for(int i=100; i>=1; i--){
                    if(dif[i].empty()) continue;
                    cout << *prev(dif[i].end()) << "\n";
                    break;
                }
            }
            else {
                for(int i=1; i<=100; i++){
                    if(dif[i].empty()) continue;
                    cout << *dif[i].begin() << "\n";
                    break;
                }
            }
        }
        else if (command == "recommend3"){
            cin >> var1 >> var2;
            int res = -1;
            if(var1 == 1){
                for(int i=var2; i<=100; i++){
                    if(dif[i].empty()) continue;
                    res = *dif[i].begin();
                    break;
                }
            }else {
                for(int i=var2-1; i>=1; i--){
                    if(dif[i].empty()) continue;
                    res = *prev(dif[i].end());
                    break;
                }
            }
            cout << res << "\n";
        }
        else if (command == "add"){
            cin >> var1 >> var2 >> var3;
            alg[var3].insert(make_pair(var2, var1));
            dif[var2].insert(var1);
            problem[var1] = make_pair(var2, var3);
        }
        else if (command == "solved"){
            cin >> var1;
            int s_dif = problem[var1].first;
            int s_alg = problem[var1].second;

            alg[s_alg].erase(make_pair(s_dif, var1));
            dif[s_dif].erase(var1);
        }
    }

    return 0;
}