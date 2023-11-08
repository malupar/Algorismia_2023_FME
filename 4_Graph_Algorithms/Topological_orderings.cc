#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> cur;
int ans = 0;
void bt(int i, int n, vector<vector<int>>& g, set<int>& s, vector<int>& cnt) {
    //cout << i << '\n';
    if (i == n) {
        ++ans;
        for (int j = 0; j < n; ++j) {
            if (j) cout << ' ';
            cout << cur[j];
        }
        cout << endl;
        return;
    }
    auto it = s.begin();
    set<int> s2 = s;
    while (it != s.end()) {
        int x = *it;
        s2.erase(x);
        cur.push_back(x);
        for (auto y: g[x]) {
            --cnt[y];
            if (!cnt[y]) {
                s2.insert(y);
            }
        }
        bt(i+1,n,g,s2,cnt);
        cur.pop_back();
        for (auto y: g[x]) {
            if (!cnt[y]) {
                s2.erase(y);
            }
            ++cnt[y];
        }
        s2.insert(x);
        ++it;
    }
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    vector<int> cnt(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        ++cnt[y];
    }

    set<int> s;
    for (int i = 0; i < n; ++i) if (!cnt[i]) s.insert(i);
    bt(0,n,g,s,cnt);
}