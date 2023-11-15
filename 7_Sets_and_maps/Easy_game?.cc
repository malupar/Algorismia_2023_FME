#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> s;
    set<pair<int,string>> t;
    int cnt = 1;
    cout << "GAME #" << cnt << endl;
    string str;
    while (cin >> str) {
        if (str == "END") {
            cout << "HAS:" << endl;
            for (auto x: s) cout << x << endl;
            cout << endl << "HAD:" << endl;
            for (auto x: t) cout  << x.second << endl;
            s.clear();
            t.clear();
            ++cnt;
            cout << endl << "GAME #" << cnt << endl;
        }
        else if (str == "QUIT") {
            cout << "HAS:" << endl;
            for (auto x: s) cout << x << endl;
            cout << endl << "HAD:" << endl;
            for (auto x: t) cout << x.second << endl;
            break;
        }
        else if (s.find(str) == s.end()) {
            s.insert(str);
            t.erase({str.size(), str});
        }
        else{
            t.insert({str.size(), str});
            s.erase(str);
        }
    }
}