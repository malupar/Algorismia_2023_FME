#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main() {
    string s;
    multiset<string> s2;
    priority_queue<string> s1;
    int cnt = 1;
    while (cin >> s) {
        if (s == "END") break;
        s2.insert(s);
        if (s1.size() < cnt/2) {
            s1.push(*s2.begin());
            s2.erase(s2.begin());
        }

        if (s1.size() && s2.size()) {
            if (s1.top() > *s2.begin()) {
                s1.push(*s2.begin());
                s2.insert(s1.top());
                s1.pop();
                s2.erase(s2.begin());
            }
        }
        if (cnt&1) cout << *s2.begin() << endl;
        else cout << s1.top() << endl;
        ++cnt;
    }
}