#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,int> s;
    string act;
    while (cin >> act) {
        if (act == "store") {
            string x;
            cin >> x;
            s[x]++;
        }
        if (act == "minimum?") {
            if (s.empty()) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << s.begin()->first << ", " << s.begin()->second << " time(s)" << endl;
        }
        if (act == "maximum?") {
            if (s.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = s.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        if (act == "delete") {
            string x;
            cin >> x;
            if (s.find(x) == s.end()) continue;
            s[x]--;
            if (!s[x]) s.erase(x);
        }
    }
}