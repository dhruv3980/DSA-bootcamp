#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<char> s;
    int flag = 1; // Assume valid unless we find redundant brackets

    string st = "(a+b)+d";

    for (int i = 0; i < st.length(); i++) {
        char ch = st[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            s.push(ch);
        } 
        else if (ch == ')') {
            bool hasOperator = false;

            // Check what’s inside the brackets
            while (!s.empty() && s.top() != '(') {
                if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/') {
                    hasOperator = true;
                }
                s.pop();
            }

            if (!hasOperator) {
                flag = 0; // Found redundant brackets
                break;
            }

            if (!s.empty()) {
                s.pop(); // Pop the matching '('
            }
        }
    }

    if (flag == 0) {
        cout << "Not valid expression" << endl;
    } else {
        cout << "valid expression" << endl;
    }

    return 0;
}
