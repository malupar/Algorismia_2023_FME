#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<int> cols, diags, diags2;
vector<vector<int>> tab;
void print(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(tab[i][j])cout<<'Q';
            else cout <<'.';
        }
        cout << endl;
    }
}

bool bad_diag(int i, int j) {
    for (int k = 1; k <= min(i, j); ++k) {
        if (tab[i-k][j-k]) return true;
    }
    for (int k = 1; k <= min(i, int(tab.size())-1-j); ++k) {
        if (tab[i-k][j+k]) return true;
    }
    return false;
}

void bt(int i, int j, int n, bool& trobat) {
    if (trobat) return;
    if (i == n) {
        ++ans;
        print(n);
        trobat = true;
        return;
    }
    if (j == n) return;
    if (cols[j] or diags[i-j+n] or diags2[i+j]) {
        bt(i,j+1,n, trobat);
        return;
    }
    if (true) {
        tab[i][j] = 1;
        cols[j] = 1;
        diags[i-j+n] = 1;
        diags2[i+j] = 1;
        bt(i+1,0,n, trobat);
        if (trobat) return;
        cols[j] = 0;
        tab[i][j] = 0;
        diags[i-j+n] = 0;
        diags2[i+j] = 0;
    }
    bt(i,j+1,n,trobat);
}

int main() {
    int n;
    cin >> n;
    cols = vector<int> (n);
    diags= vector<int>(2*n+1);
    diags2= vector<int>(2*n+1);
    tab = vector<vector<int>> (n, vector<int>(n));
    bool trobat = false;
    bt(0, 0, n, trobat);
    if (not trobat) cout << "NO SOLUTION" << endl;
}