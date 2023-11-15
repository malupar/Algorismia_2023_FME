#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<stack<string>> library(n);
    cin.get();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        istringstream fin(s);
        stack<string> stk;
        string name;
        while (fin >> name) {
            stk.push(name);
        }

        library[i] = stk;
    }

    string s;
    while (cin >> s) {
        string ret;
        if (s == "RETURN") cin >> ret;
        int t;
        cin >> t;
        if (t < 1 || t > n) continue;
        if (s == "LOAN" && library[t-1].size()) library[t-1].pop();
        else library[t-1].push(ret);
    }

    for (int i = 0; i < n; ++i) {
        cout << "Stack " << i+1 << ":";
        stack<string> cur;
        while (library[i].size()) {
            cur.push(library[i].top());
            library[i].pop();
        }
        while (cur.size()) {
            if (cur.top() != "")cout << ' ' << cur.top();
            cur.pop();
        }
        cout << endl;
    }
}