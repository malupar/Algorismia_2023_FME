#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    map<string, int> elo;
    map<string, bool> connected;
    string act;
    while (cin >> act) {
        if (act == "LOGIN") {
            string x;
            cin >> x;
            connected[x] = true;
            if (elo.find(x) == elo.end()) elo[x] = 1200;
        }
        if (act == "LOGOUT") {
            string x;
            cin >> x;
            connected[x] = false;
        }
        if (act == "PLAY") {
            string x, y;
            cin >> x >> y;
            if (!connected[x] or !connected[y]) {
                cout << "player(s) not connected" << endl;
            }
            else {
                elo[x] += 10;
                elo[y] = max(elo[y]-10, 1200);
            }
        }
        if (act == "GET_ELO") {
            string x;
            cin >> x;
            cout << x << ' ' << elo[x] << endl;
        }
    }

    cout << endl << "RANKING" << endl;
    vector<pair<int,string>> r;
    for (auto x: elo) r.push_back({-x.second, x.first});
    sort(r.begin(), r.end());
    for (auto x: r) cout << x.second << ' ' << -x.first << endl;
}