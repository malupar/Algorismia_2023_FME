#include <map>
#include <iostream>
#include <set>
using namespace std;

int main() {
    string act;
    map<string, string> mp;
    set<string> alone;
    while (cin >> act) {
        if (act == "info"){
            cout << "COUPLES:" << endl;
            for (auto x: mp) if (x.first < x.second) cout << x.first << ' ' << x.second << endl;
            cout << "ALONE:" << endl;
            for (auto x: alone) cout << x << endl;
            cout << "----------" << endl;
        }
        else {
            string x, y;
            cin >> x >> y;
            if (mp.find(x) != mp.end() && mp[x] != y) {
                alone.insert(mp[x]);
                mp.erase(mp[x]);
            }
            if (mp.find(y) != mp.end() && mp[y] != x) {
                alone.insert(mp[y]);
                mp.erase(mp[y]);
            }
            alone.erase(x);
            alone.erase(y);
            mp[x] = y;
            mp[y] = x;
        }
    }
}