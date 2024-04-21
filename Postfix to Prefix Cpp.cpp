#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfix_to_prefix(const string& postfix) {
    stack<string> s;
    int length = postfix.length();

    for (int i = 0; i < length; i++) {
        if (!isOperator(postfix[i])) {
            string operand(1, postfix[i]);
            s.push(operand);
        }
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = postfix[i] + op2 + op1;
            s.push(temp);
        }
    }

    return s.top();
}

int main() {
    string postfix_expr;
    cout << "Enter the postfix expression: ";
    cin >> postfix_expr;

    reverse(postfix_expr.begin(), postfix_expr.end());

    string prefix_expr = postfix_to_prefix(postfix_expr);

    cout << "Prefix expression: " << prefix_expr << endl;

    return 0;
}
