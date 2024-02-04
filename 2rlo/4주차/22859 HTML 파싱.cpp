// BOJ 22859 HTML 파싱 https://www.acmicpc.net/problem/22859
// Created by JEY on 2024-01-27.

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

stack<char> s;
stack<string> res;

void getTitle(string word){
    string title = "";
    int idx = word.find('"');
    while(word[++idx] != '"')
        title += word[idx];

    cout << "title : " << title << "\n";
}

string makeWord(){
    string tmp = "";
    while(!s.empty()){
        tmp.insert(tmp.begin(), s.top());
        s.pop();
    }

    return tmp;
}

string removeEmpty(string word){
    if(word.empty() || word.length() <= 1)
        return word;

    string str = "";
    int cnt = 0;
    for(int i=0; i<word.length(); i++){
        if(word[i] == ' ')
            cnt++;
        else
            cnt = 0;

        if(cnt < 2)
            str.push_back(word[i]);
    }

    return str;
}

string trim(string word) {
    if(word.length() <= 1)
        return word;
    if(word[0] == '<'){
        while(word[1] == ' ')
            word.erase(word.begin()+1);
        while(word[word.size()-2] == ' ')
            word.erase(word.begin()+word.size()-2);
    }
    else {
        while(word[0] == ' ')
            word.erase(word.begin());
        while(word[word.size()-1] == ' ')
            word.erase(word.begin()+word.size()-1);
    }

    return word;
}

void print(string endTag){
    vector<string> print;
    while(res.top().compare(endTag) !=0) {
        string str = res.top();
        res.pop();
        print.push_back(str);
    }

    if(!res.empty())
        res.pop();

    string out = "";
    reverse(print.begin(), print.end());

    for(auto it : print)
        out.append(it);

    out = removeEmpty(out);
    out = trim(out);
    cout << out << "\n";
}

void classify(string str){
    if(str.empty()) return;
    if(str[0] == '<'){
        if(str.find('/') == string::npos){
            if(str.compare("<main>") == 0 || str.compare("<p>") == 0)
                res.push(str);
            else if (str.find("<div title=") != string::npos){
                if(str.find('"') != string::npos){
                    getTitle(str);
                }
            }
        }
        else {
            int idx = str.find('/');
            str.erase(str.begin()+idx);
            if(str.compare("<main>") == 0 || str.compare("<p>") == 0){
                print(str);
            }
        }
    }
    else
        res.push(str);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string html;
    getline(cin, html);

    for(int i=0; i<html.length(); i++){
        string str = "";

        switch(html[i]){
            case '<' :
                if(!s.empty()){
                    str = makeWord();
                    classify(str);
                    str.clear();
                }
                s.push(html[i]);
                break;

            case '>':
                s.push(html[i]);
                str = makeWord();
                classify(str);
                str.clear();
                break;

            default:
                s.push(html[i]);
        }
    }

    return 0;
}