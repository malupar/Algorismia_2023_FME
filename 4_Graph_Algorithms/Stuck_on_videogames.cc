#include<iostream>
#include<vector>
#include <queue>
#include <map>
using namespace std;

const int max_n = 500*500;
const int max_v = 10;

bool valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m; 
}

int main() {
    int t;
    cin >> t;
    int dist[max_n][4];
    for (int tes = 0; tes < t; ++tes) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};
        map<char,int> mp;
        mp['L'] = 0;
        mp['W'] = 2;
        mp['S'] = 1;
        mp['N'] = 3;
        mp['I'] = 3;
        pair<int,int> st, fini;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'I') st = {i, j};
                if (grid[i][j] == 'F') fini = {i, j};
            }
        }
        for (int i = 0; i < n*m; ++i)
            for (int j = 0; j < 4; ++j) dist[i][j] = 1e9;
        queue<pair<int,int>> q;
        int s= st.first*m+st.second;
        for (int i = 0; i < 4; ++i) {
            dist[s][i] = i;
            q.push({s, i});
        }
        while (!q.empty()) {
            int u = q.front().first, par = q.front().second;
            q.pop();
            int x = u/m, y = u%m;
            pair<int,int> w = mov[(par+mp[grid[x][y]])%4];
            if (valid(x+w.first,y+w.second,n,m) && grid[x+w.first][y+w.second] != 'X') {
                int to = (x+w.first)*m+y+w.second;
                if (dist[to][(par+1)%4] > dist[u][par]+1) {
                    dist[to][(par+1)%4] = dist[u][par]+1;
                    q.push({to, (par+1)%4});
                } 
            }
            if (dist[u][(par+1)%4] > dist[u][par]+1) {
                dist[u][(par+1)%4] = dist[u][par]+1;
                q.push({u, (par+1)%4});
            }
        }
        int to = fini.first*m+fini.second;
        int ans = min(min(dist[to][0], dist[to][1]), min(dist[to][2], dist[to][3]));
        if (ans >= 1e9) cout << '#' << tes+1 << ": impossible" << endl;
        else  cout << '#' << tes+1 << ": " << ans << endl;
    }
}