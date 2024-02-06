// BOJ 22860 폴더 정리 https://www.acmicpc.net/problem/22860
// Created by JEY on 2024-01-27.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

unordered_map<string, vector<pair<int, string>>> structure;
unordered_map<string, int> visited;
int kind, count;

void dfs(string node) {
    for(auto it: structure[node]){
        if(it.first == 0){
            if(!visited[it.second]){
                visited[it.second] = 1;
                kind++;
            }
            count++;
        }
        if(it.first == 1)
            dfs(it.second);
    }
}

vector<string> folder(string queries){
    vector<string> v;
    istringstream ss(queries);
    string stringbuffer;

    while(getline(ss, stringbuffer, '/')){
        v.push_back(stringbuffer);
    }

    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int totalFolder, totalFile, totalQueries;
    cin >> totalFolder >> totalFile;

    for(int i=0; i<totalFolder+totalFile; i++){
        string parentFolder, child;
        int distinguish;
        cin >> parentFolder >> child >> distinguish;
        vector<pair<int, string>> v = structure[parentFolder];
        v.push_back({distinguish, child});
        structure[parentFolder] = v;
    }

    cin >> totalQueries;
    for(int i=0; i<totalQueries; i++){
        string queries;
        cin >> queries;
        vector<string> v = folder(queries);
        dfs(v.back());
        cout << kind << ' ' << count << '\n';
        kind = 0;
        count = 0;
        visited.clear();
    }
    return 0;
}