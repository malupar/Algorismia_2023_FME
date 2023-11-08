#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m; 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dist(n*m, 1e9);
    vector<pair<int,int>> mov = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            cin >> grid[i][j];
    }
    int x, y;
    cin >> x >> y;
    --x;--y;
    queue<int> q;
    int ans = -1;
    dist[x*m+y] = 0;
    q.push(x*m+y);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int x2 = u/m, y2 = u%m;
        if (grid[x2][y2] == 't') {
            ans = dist[u];
        }
        for (auto w: mov) {
            if (valid(x2+w.first, y2+w.second, n, m) && grid[x2+w.first][y2+w.second] != 'X') {
                int to = (x2+w.first)*m+y2+w.second;
                if (dist[to] > dist[u]+1) {
                    dist[to] = dist[u]+1;
                    q.push(to);
                }
            }
        }
    }
    if (ans == -1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << ans << endl;
}