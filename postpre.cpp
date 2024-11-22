#include <iostream>
#include <stack>
using namespace std;

int prefixev(string s) {
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            int op1 = st.top(); 
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        st.push(op1 / op2);
                    } else {
                        cout << "Division by zero error" << endl;
                        return -1;
                    }
                    break;
                default:
                    cout << "Invalid Operator" << endl;
                    return -1;
            }
        }
    }
    return st.top();
}

int postfixev(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        st.push(op1 / op2);
                    } else {
                        cout << "Division by zero error" << endl;
                        return -1;
                    }
                    break;
                default:
                    cout << "Invalid Operator" << endl;
                    return -1;
            }
        }
    }
    return st.top();
}

int main() {
    string prefix_expr = "-+7*45+20";
    string postfix_expr = "74*5+20+-";
    
    cout << "Prefix Evaluation of " << prefix_expr << ": " << prefixev(prefix_expr) << endl;
    cout << "Postfix Evaluation of " << postfix_expr << ": " << postfixev(postfix_expr) << endl;

    return 0;
}
