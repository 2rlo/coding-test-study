// BOJ 22859 HTML 파싱 https://www.acmicpc.net/problem/22859
// Created by 윤혜경 on 1/26/24.

#include <bits/stdc++.h>
using namespace std;

int i = 0;
string input;
vector<string> v;
bool first = true;

string open() {
    i++;
    string tag = "";
    while (input[i] != '>') {
        tag += input[i++];
        if (tag == "div")
            return tag;
    }
    v.push_back(tag);
    i++;
    return tag;
}

string close() {
    i += 2;
    string tag;
    while (input[i] != '>')
        tag += input[i++];
    if (v.back() == tag)
        v.pop_back();
    i++;
    return tag;
}

string erase1(string str) {
    while (str.front() == ' ')
        str.replace(0, 1, "");
    while (str.back() == ' ')
        str.replace(str.size() - 1, 1, "");
    return str;
}

string erase2(string str) {
    int i = 0;
    string re = "";
    while (i < str.size()) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            i++;
            continue;
        } else {
            re += str[i++];
        }
    }
    return re;
}

void p() {
    string tag = "";
    string str = "";
    while (true) {
        if (input[i] == '<' && input[i + 1] != '/') {
            tag = open();
            if (tag == "br ")
                v.pop_back();
            continue;
        } else if (input[i] == '<' && input[i + 1] == '/') {
            tag = close();
            if (tag == "p") {
                cout << '\n' << erase2(erase1(str));
                break;
            }
            continue;
        }
        str += input[i++];
    }
    return;
}

void div() {
    if (first)
        first = false;
    else
        cout << '\n';

    i += 8;
    cout << "title : ";
    while (input[i] != '\"')
        cout << input[i++];
    i += 2;

    string tag = "";
    while (true) {
        if (input[i] == '<' && input[i + 1] != '/') {
            tag = open();
        } else if (input[i] == '<' && input[i + 1] == '/') {
            tag = close();
            if (tag == "div")
                break;
            tag = "";
        }

        if (tag == "p")
            p();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin, input);

    string tag = "";
    while (true) {
        if (input[i] == '<' && input[i + 1] != '/')
            tag = open();
        else if (input[i] == '<' && input[i + 1] == '/') {
            tag = close();
            if (tag == "main")
                break;
        }

        if (tag == "div")
            div();
    }
    return 0;
}