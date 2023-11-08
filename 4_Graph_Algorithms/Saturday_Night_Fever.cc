#include<iostream>
#include<vector>
#include <queue>
using namespace std;

const int max_n = 1e5;
const int max_v = 10;

int main() {
    int dp[max_n][max_v];
    int n, x, y;
    while (cin >> n >> x >> y) {
        --x;--y;
        int m;
        vector<vector<int>> g(n, vector<int>());
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            --u;--v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int v;
        cin >> v;
        vector<int> sbire(v);
        for(int& i: sbire) {
            cin >> i;
            --i;
        }
        for (int i = 0; i < n; ++i) for(int j = 0; j < v; ++j) dp[i][j] = -1;
        queue<pair<int,int>> q;
        for (int i = 0; i < v; ++i) {
            if (sbire[i] == y) continue;
            dp[y][i] = 0;
            q.push({y, i});
        }
        while (!q.empty()) {
            int u = q.front().first, sb = q.front().second;
            q.pop();
            if (sbire[((v-1+sb)%v)] != u && dp[u][(v-1+sb)%v] == -1) {
                dp[u][(v-1+sb)%v] = dp[u][sb]+1;
                q.push({u, (v-1+sb)%v});
            }
            for (int w: g[u]) {
                if (sbire[(v-1+sb)%v] == w) continue;
                if (sbire[sb] == w && sbire[(v-1+sb)%v] == u) continue;
                if (dp[w][(v-1+sb)%v] == -1) {
                    dp[w][(v-1+sb)%v] = dp[u][sb]+1;
                    q.push({w, (v-1+sb)%v});
                }
            }
        }
        int ans = dp[x][0];
        if (ans == -1) cout << "Tu es foutu, Evariste!" << endl;
        else if (ans == 1) cout << "C'est une minute, Evariste!" << endl;
        else cout << "Ce sont " << ans << " minutes, Evariste!" << endl;
    }
}