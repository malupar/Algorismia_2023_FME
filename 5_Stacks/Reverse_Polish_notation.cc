#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        istringstream fin(s);
        string st;
        stack<int> stk;
        while (fin >> st) {
            if (st == "+") {
                int x = stk.top();
                stk.pop();
                stk.top() += x;
            }
            else if (st == "-") {
                int x = stk.top();
                stk.pop();
                stk.top() -= x;
            }
            else if (st == "*") {
                int x = stk.top();
                stk.pop();
                stk.top() *= x;
            }
            else stk.push(stoi(st));
        }
        cout << stk.top() << endl;    
    }
}