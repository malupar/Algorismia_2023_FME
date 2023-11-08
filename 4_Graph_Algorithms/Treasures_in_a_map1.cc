#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool dfs(int u, VVI& g, VI& t, VI& seen) {
    if (t[u]) return true;
    seen[u] = true;
    for (int v: g[u]) {
        if (!seen[v] && dfs(v, g, t, seen)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    VVI g(n*m, VI());
    VI t(n*m), seen(n*m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == 'X') {
                t[i*m+j]=-1;
                continue;
            }
            if (c == 't') t[i*m+j] = 1;
            if (i && t[i*m+j-m] != -1) {
                g[i*m+j].push_back(i*m+j-m);
                g[i*m+j-m].push_back(i*m+j);
            }
            if (j && t[i*m+j-1] != -1) {
                g[i*m+j].push_back(i*m+j-1);
                g[i*m+j-1].push_back(i*m+j);
            }
        }
    }
    int x, y;
    cin >> x >> y;
    --x;--y;
    if (dfs(x*m+y, g, t, seen)) cout << "yes" << endl;
    else cout << "no" << endl;
}