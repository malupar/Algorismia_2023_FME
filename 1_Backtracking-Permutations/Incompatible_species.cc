#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char,int> mp;

void bt (int i, int n, vector<char>& pos, vector<bool>& seen, vector<char>& cur, vector<vector<int>>& ok) {
    if (i == n) {
        for (auto x: cur) cout << x;
        cout << endl;
    }
    else {
        for (auto j : ok[mp[cur.back()]]) {
            if (!seen[j]) {
                seen[j] = true;
                cur.push_back(pos[j]);
                bt (i+1, n, pos, seen, cur, ok);
                cur.pop_back();
                seen[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<bool>> ok (n, vector<bool>(n, true));
    vector<vector<int>> g (n, vector<int>());
    vector<bool> seen (n, false);
    vector<char> pos (n), cur;
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
        mp[pos[i]] = i;
    }
    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        ok[mp[s[0]]][mp[s[1]]] = ok[mp[s[1]]][mp[s[0]]] = false;
    }
    for (int i = 0; i < n; ++i) {
        ok[i][i] = false;
        for (int j = 0; j < n; ++j) {
            if (ok[i][j]) g[i].push_back (j);
        }
    }
    for (int i = 0; i < n; ++i) {
        cur.push_back (pos[i]);
        seen[i] = true;
        bt(1, n, pos, seen, cur, g);
        cur.pop_back();
        seen[i] = false;
    }
}