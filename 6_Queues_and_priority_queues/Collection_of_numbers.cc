#include <iostream>
#include <set>
using namespace std;

int main() {
    char c;
    multiset<int> s;
    while (cin >> c) {
        if (c == 'A') {
            if (s.empty()) cout << "error!" << endl;
            else {
                auto it = s.end();
                --it;
                cout << *it << endl;
            }
        }
        else if (c == 'S') {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (c == 'R') {
            if (s.empty()) cout << "error!" << endl;
            else {
                auto it = s.end();
                --it;
                it = s.erase(it);
            }
        }
        else if (c == 'I') {
            int x;
            cin >> x;
            if (s.empty()) cout << "error!" << endl;
            else {
                auto it = s.end();
                --it;
                s.insert(*it+x);
                it = s.erase(it);
            }
        }
        else {
            int x;
            cin >> x;
            if (s.empty()) cout << "error!" << endl;
            else {
                auto it = s.end();
                --it;
                s.insert(*it-x);
                it = s.erase(it);
            }
        }
    }
}
