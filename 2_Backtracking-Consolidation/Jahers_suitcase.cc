#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tab;
vector<pair<int,int>> ob;
vector<bool> used;
int ans = 0;
void full(int i, int j, int i2, int j2) {
    for (int k = i; k < i2; ++k) {
        for (int k2 = j; k2 < j2; ++k2) {
            tab[k][k2] = 1-tab[k][k2];
        }
    }
}

bool check(int i, int j, int i2, int j2) {
    for (int k = i; k < i2; ++k) {
        for (int k2 = j; k2 < j2; ++k2) {
            if (tab[k][k2]) {
                return false;
            }
        }
    }
    return true;
}

void bt(int i, int j, int n, int a, int b) {
    if (i == a) {
        ++ans;
        return;
    }
    if (j == b) {
        bt(i+1, 0, n, a, b);
        return;
    }
    if (tab[i][j]) {
        bt(i, j+1, n, a, b);
        return;
    }
    for (int k = 0; k < n; ++k) {
        if (used[k])continue;
        if (i+ob[k].first<=a && j+ob[k].second<=b && check(i,j,i+ob[k].first,j+ob[k].second)) {
            full(i,j,i+ob[k].first,j+ob[k].second);
            used[k] = true;
            bt(i,j+ob[k].second,n,a,b);
            used[k] = false;
            full(i,j,i+ob[k].first,j+ob[k].second);
        }
    }
}

int main() {
    int a,b,n,test =1;
    while (cin >> a >> b >> n) {
        ans = 0;
        tab = vector<vector<int>> (a, vector<int>(b));
        ob = vector<pair<int,int>> (n);
        used = vector<bool> (n);
        for (auto& i: ob) cin >> i.first >> i.second;
        bt(0, 0, n, a, b);
        cout <<'#' << test << ": " << ans << endl;
        ++test;
    }
}
