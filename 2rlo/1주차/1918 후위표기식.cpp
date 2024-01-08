// BOJ 1918 후위표기식 https://www.acmicpc.net/problem/1918

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string infix;
    stack<char> op;

    cin >> infix;

    for(int i=0; i<infix.length(); i++){
        if(infix[i]>='A' && infix[i] <= 'Z'){
            cout << infix[i];
        }
        else{
            if(infix[i] == '('){
                op.push(infix[i]);
            }
            else if (infix[i] == '*' || infix[i] == '/'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    cout << op.top();
                    op.pop();
                }
                op.push(infix[i]);
            }
            else if (infix[i] == '+' || infix[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    cout << op.top();
                    op.pop();
                }
                op.push(infix[i]);
            }
            else if(infix[i] == ')'){
                while(!op.empty() && op.top() != '('){
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
        }
    }

    while(!op.empty()){
        cout << op.top();
        op.pop();
    }

    return 0;
}