#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m; 
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> grid(n, vector<char>(m));
        vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<int> q;
        vector<int> dist(n*m, 1e9), num(n*m);
        int target = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'T') target = i*m+j;
            }
        }
        if (grid[0][0] == 'P') num[0] = 1;
        if (target == -1) cout << "The telecos ran away." << endl;
        else {
            q.push(0);
            dist[0] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                int x = u/m, y = u%m;
                for (auto w: mov) {
                    if (valid(x+w.first, y+w.second, n, m) && grid[x+w.first][y+w.second] != '#') {
                        int to = (x+w.first)*m+y+w.second;
                        if (dist[to] > dist[u]+1 || (dist[to] == dist[u]+1 && num[to] < num[u]+(grid[x+w.first][y+w.second]=='P'))) {
                            dist[to] = dist[u]+1;
                            num[to] = num[u]+(grid[x+w.first][y+w.second]=='P');
                            q.push(to);
                        }
                    }
                }
            }
            
            if (dist[target] == 1e9) cout << "The telecos is hidden." << endl;
            else cout << dist[target] << ' ' << num[target] << endl;
        }
    }
}