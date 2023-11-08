#include <iostream>
#include <vector>
using namespace std;

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m; 
}
int cnt;
vector<pair<int,int>> mov = {{1, 1}, {1,-1},{-1,1},{-1,-1}};
int dfs(int u, int n, int m, vector<vector<int>>& grid, vector<bool>& seen) {
    seen[u] = true;
    ++cnt;
    int x = u/m, y = u%m, ans = 0;
    ans += grid[x][y];
    for (auto w: mov) {
        if (valid(x+w.first, y+w.second,n,m) && grid[x+w.first][y+w.second] != -1) {
            int to = (x+w.first)*m+y+w.second;
            if (!seen[to])
                ans += dfs(to,n,m,grid,seen);
        }
    }
    return ans;
} 

int main() {
    int n, m;
    int test;
    cin >> test;
    for (int tes = 0; tes < test; ++tes) {
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        vector<bool> seen(n*m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string s;
                cin >> s;
                if (s == "X") grid[i][j] = -1;
                else grid[i][j] = stoi(s);
            }
        }
        bool ok = true;
        int best = -1;
        for (int i = 0; i < n*m; ++i) {
            if (!seen[i] && grid[i/m][i%m] != -1) {
                cnt = 0;
                int x = dfs(i, n, m, grid, seen);
                if (x%cnt) {
                    ok = false;
                    break;
                }
                else if (best != -1 && best != x/cnt) {
                    ok = false;
                    break;
                }
                else best = x/cnt;
            }
        }
        if (ok) cout << "Case " << tes+1 << ": yes" << endl;
        else cout << "Case " << tes+1 << ": no" << endl;
    }
}