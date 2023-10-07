#include <iostream>
#include <vector>

using namespace std;

void bt (int i, int j, int n, int m, vector<int>& row, vector<int>& col, vector<vector<char>>& grid, int cnt) {
    if (i == n and cnt == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << grid[i][j];
            cout << '\n';
        }
        cout << "\n";

    }else if (i < n){
        if (!row[i] and !col[j]) {
            grid[i][j] = 'R';
            row[i] = col[j] = 1;
            if (j == m-1) bt (i+1, 0, n, m, row, col, grid, cnt + 1);
            else bt (i, j+1, n, m, row, col, grid, cnt + 1);
            grid[i][j] = '.';
            row[i] = col[j] = 0;
        }
        if (j == m-1) bt (i+1, 0, n, m, row, col, grid, cnt);
        else bt (i, j+1, n, m, row, col, grid, cnt);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid (n, vector<char> (m, '.'));
    vector<int> row (n), col (m);

    bt (0, 0, n, m, row, col, grid, 0);
}