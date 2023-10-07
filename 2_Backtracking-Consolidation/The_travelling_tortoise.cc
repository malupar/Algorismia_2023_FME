#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> VVC;
typedef vector<char> VC;

typedef vector<vector<bool>> VVB;
typedef vector<bool> VB;

VVC grid;
VVB seen;
VC cur;

int st_x, st_y;
int e_x, e_y;

void print() {
    for (int i = 0; i < (int)cur.size(); ++i) cout << cur[i];
    cout << grid[e_x][e_y];
    cout << endl;
}

void bt(int i, int j, int n, int m) {
    if (i >= n || i < 0 || j < 0 || j >= m) return;
    if (i == e_x && j == e_y) {
        print();
        return;
    }
    if (seen[i][j]) return;
    cur.push_back(grid[i][j]);
    seen[i][j] = true;
    bt(i+1, j, n, m);
    bt(i-1, j, n, m);
    bt(i, j+1, n, m);
    bt(i, j-1, n, m);
    seen[i][j] = false;
    cur.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    grid = VVC(n, VC(m));
    seen = VVB(n, VB(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    cin >> st_x >> st_y >> e_x >> e_y;
    bt(st_x, st_y, n, m);
}
