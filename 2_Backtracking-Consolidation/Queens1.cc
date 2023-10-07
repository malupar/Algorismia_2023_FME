#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

bool bad_diag(int i, int j, vector<vector<int>>& tab) {
    for (int k = 1; k <= min(i, j); ++k) {
        if (tab[i-k][j-k]) return true;
    }
    for (int k = 1; k <= min(i, int(tab.size())-1-j); ++k) {
        if (tab[i-k][j+k]) return true;
    }
    return false;
}

void bt(int i, int j, int n, vector<int>& cols, vector<vector<int>>& tab) {
    if (i == n) {
        ++ans;
        return;
    }
    if (j == n) return;
    if (cols[j]) {
        bt(i,j+1,n,cols,tab);
        return;
    }
    if (not bad_diag(i, j, tab)) {
        tab[i][j] = 1;
        cols[j] = 1;
        bt(i+1,0,n,cols,tab);
        cols[j] = 0;
        tab[i][j] = 0;
    }
    bt(i,j+1,n,cols,tab);
}

int main() {
    int n;
    cin >> n;
    vector<int> cols(n);
    vector<vector<int>> tab(n, vector<int>(n));
    bt(0, 0, n, cols, tab);
    cout << ans << endl;
}
