#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, int par, vector<vector<int>>& g, vector<bool>& seen) {
    seen[u] = true;
    for (int v: g[u]) {
        if (v == par) continue;
        if (seen[v]) return false;
        if (!dfs(v, u, g, seen)) return false;
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> g(n, vector<int>());
        vector<bool> seen(n);
        while (m--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int cnt = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                if (!dfs(i,i,g,seen)) ok = false;
                ++cnt;
            }
        }
        if (ok) cout << cnt << endl;
        else cout << "no" << endl;
    }
}