#include <bits/stdc++.h>
using namespace std;

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m; 
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> dist(n*m, vector<int>(2, 1e9));
        queue<pair<int,int>> q;
        vector<bool> seen(n*m, false);
        vector<vector<pair<int,int>>> mov(2, vector<pair<int,int>>());
        mov[0] = {{1,1},{1,-1},{-1,1},{-1,-1}};
        mov[1] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'B') {
                    q.push({i*m+j,0});
                    dist[i*m+j][0] = 0;
                }
                if (grid[i][j] == 'K') {
                    q.push({i*m+j,1});
                    dist[i*m+j][1] = 0;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int u = q.front().first, p = q.front().second;
            q.pop();
            int x = u/m, y = u%m;
            
            if ('0' <= grid[x][y] && grid[x][y] <= '9' && !seen[u]) {
                ans += grid[x][y]-'0';
                seen[u] = true;
            }
            for (auto w: mov[p]) {
                if (valid(x+w.first, y+w.second, n, m) && grid[x+w.first][y+w.second] != 'T') {
                    int to = (x+w.first)*m+y+w.second;
                    if (dist[to][p] > dist[u][p]+1) {
                        dist[to][p] = dist[u][p]+1;
                        q.push({to, p});
                    }
                }
            }
        }
        cout << ans << endl;
    }
}