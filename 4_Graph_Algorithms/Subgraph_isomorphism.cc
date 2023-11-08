#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
bool bt(int i, int n, VI& deg1, VI& deg2, vector<bool>& seen1, vector<bool>& seen2, VVI& edg1, VVI& edg2, VI& bij) {
    if (i == n) {
        //Hemos encontrado una f valida
        return true;
    }
    //buscamos j tq f(i) = j
    for (int j = 0; j < n; ++j) {
        if (seen2[j]) continue;
        if (deg1[i] == deg2[j]) {
            bool oki = true;
            //Miramos que las aristas ya asignadas sean correctas
            for (int k = 0; k < n; ++k) {
                if (!seen1[k]) continue;
                if (edg1[i][k] != edg2[j][bij[k]]) {
                    oki = false;
                    break;
                }
            }
            if (oki) {
                seen1[i] = seen2[j] = true;
                bij[i] = j;
                if (bt(i+1, n, deg1, deg2, seen1, seen2, edg1, edg2, bij)) return true;
                bij[i] = -1;
                seen1[i] = seen2[j] = false;
            }
        }
    }
    return false;
}

bool change(map<int,int> mp, VVI& edg, VVI& edg2) {
    int n = mp.size();
    if (edg.size() != edg2.size()) return false;
    vector<bool> seen(n, false), seen2(n, false);
    VI cnt(n), cnt2(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cnt[i] += edg[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cnt2[i] += edg2[i][j];
        }
    }
    vector<int> bij(n);
    return (bt(0, n, cnt, cnt2, seen, seen2, edg, edg2, bij));
}

void dfs(int u, vector<bool>& seen, VVI& g, map<int,int>& mp) {
    mp[u] = mp.size();
    seen[u] = true;
    for (int v: g[u]) {
        if (!seen[v])
            dfs(v, seen, g, mp);
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VVI g(n, VI());
        VI sz;
        vector<bool> seen(n, false);
        vector<VVI> stored;
        while (m--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                map<int,int> mp;
                dfs(i, seen, g, mp);
                VVI edg(mp.size(), VI(mp.size()));
                for (auto x: mp) {
                    for (auto y: g[x.first])
                        edg[x.second][mp[y]] = 1;
                }
                int ans = -1;
                for (int j = 0; j < stored.size(); ++j)
                    if (change(mp, edg, stored[j])) {
                        ans = j;
                        break;
                    }
                if(ans == -1) {
                    stored.push_back(edg);
                    sz.push_back(1);
                }
                else 
                    ++sz[ans];
            }
        }
        int ans = 0;
        for (auto x: sz) ans += x*(x-1)/2;
        cout << ans << endl;
    }
}