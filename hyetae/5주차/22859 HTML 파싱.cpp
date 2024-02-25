// BOJ 22859 HTML 파싱 https://www.acmicpc.net/problem/22859
// Created by 윤혜경 on 1/26/24.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string html;
    getline(cin, html);

    html = regex_replace(html, regex(R"(<main>)"), "");
    html = regex_replace(html, regex(R"(</main>)"), "");

    html = regex_replace(html, regex(R"(<div title=\"([\w ]*)\">)"), "title : $1\n");
    html = regex_replace(html, regex(R"(</div>)"), "");

    html = regex_replace(html, regex(R"(<p>)"), "");
    html = regex_replace(html, regex(R"(</p>)"), "\n");

    html = regex_replace(html, regex(R"(</?[\w ]*>)"), "");

    html = regex_replace(html, regex(R"( ?\n ?)"), "\n");
    html = regex_replace(html, regex(R"( {2,})"), " ");

    cout << html;

    return 0;
}