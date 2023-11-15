#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' or s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    st.push('(');
                    break;
                }
                if (s[i] == ')' and st.top() != '(') 
                    break;
                else if (s[i] == ')'){
                    st.pop();
                }
                else if (s[i] == ']' and st.top() != '[') 
                    break;
                else st.pop();
            }
        }
        if (st.empty()) cout << s << " is correct" << endl;
        else cout << s << " is incorrect" << endl;
    }
}