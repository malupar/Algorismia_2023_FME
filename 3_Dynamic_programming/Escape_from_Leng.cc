#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9+7;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<VVVI> VVVVI;

VVVVI dp;

ll DP(int i, int j, int l, int n, int m, VVI& grid, int last_mov) {
    if (i < 0 || j < 0 || i == n || j == m || l < 0) return 0;
    if (grid[i][j]) return 0;
    if (dp[i][j][l][last_mov] != -1) return dp[i][j][l][last_mov];
    ll ans = 0;
    if (last_mov) {
        for (int k = j+1; k < m; ++k) {
            if (k == j) continue;
            if (grid[i][k]) break;
            ans += DP(i, k, l-1, n, m, grid, 0);
        }
        for (int k = j-1; k >= 0; --k) {
            if (k == j) continue;
            if (grid[i][k]) break;
            ans += DP(i, k, l-1, n, m, grid, 0);
        }
    }
    ans += DP(i-1, j, l, n, m, grid, 1);
    return dp[i][j][l][last_mov] = ans;
}

int main() {
    int n, m, l;
    VVI grid;
    while (cin >> n >> m >> l) {
        if(!n && !m && !l) break;
        pair<int,int> st, f;
        dp = VVVVI(n, VVVI(m, VVI(l+1, VI(2, -1))));
        grid = VVI (n, VI(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                if (c == 'O') {
                    for (int k = -2; k <= 2; ++k) {
                        for (int k2 = -2; k2 <= 2; ++k2) {
                            if (0<=i+k && i+k < n && j+k2 >= 0 && j+k2 < m) 
                                grid[i+k][j+k2] = 1;
                        }
                    }
                }
                else if (c == 'D') {
                    st = {i, j};
                }
                else if (c == 'P') {
                    f = {i, j};
                }
            }
        }
        dp[st.first][st.second][0][0]=dp[st.first][st.second][0][1] = 1;
        ll ans = 0;
        for (int i = 0; i <= l; ++i) {
            ans += DP(f.first, f.second, i, n, m, grid, 1);
        }
        if (!ans) cout << "Good bye, Professor Dyer!" << endl;
        else cout << ans << endl;
    }
}