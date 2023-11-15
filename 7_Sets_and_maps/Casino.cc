#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,int> mp;
    string s, act;
    while (cin >> s >> act) {
        int x;
        if (act == "wins") cin >> x;
        if (act != "enters" and mp.find(s) == mp.end()) cout << s << " is not in the casino" << endl;
        else if (act == "enters" and mp.find(s) != mp.end()) cout << s << " is already in the casino" << endl;
        else {
            if (act == "wins") mp[s] += x;
            if (act == "enters") mp[s] = 0;
            if (act == "leaves") {
                cout << s << " has won " << mp[s] << endl;
                mp.erase(s);
            }
        }
    }
    cout << "----------" << endl;
    for (auto x: mp) {
        cout << x.first << " is winning " << x.second << endl;
    }
}