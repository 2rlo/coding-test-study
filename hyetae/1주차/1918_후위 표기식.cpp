#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;

    vector<char> op;
    for (char c: input) {
        if (isalpha(c)) {
            cout << c;
            continue;
        }
        if (c == '(')
            op.push_back(c);
        else if (c == ')') {
            while (!op.empty() && op.back() != '(') {
                cout << op.back();
                op.pop_back();
            }
            op.pop_back();
        } else if (c == '*' || c == '/') {
            while (!op.empty() && (op.back() == '*' || op.back() == '/')){
                cout << op.back();
                op.pop_back();
            }
            op.push_back(c);
        } else if (c == '+' || c == '-') {
            while (!op.empty() && op.back() != '(') {
                cout << op.back();
                op.pop_back();
            }
            op.push_back(c);
        }

    }

    while (!op.empty()) {
        cout << op.back();
        op.pop_back();
    }

    return 0;
}