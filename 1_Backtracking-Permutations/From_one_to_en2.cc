#include <iostream>
#include <vector>

using namespace std;

void bt (int i, int cur, int n, vector<int>& p, vector<bool>& seen) {
    //cout << i << ' ';
    if (cur == n-1) {
        for (int j = 0; j < n; ++j) {
            if (!seen[j]) p[i] = j+1;
        }
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ',';
            cout << p[i];
        }
        cout << ")\n";
        p[i] = -1;
    }
    else {
        p[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (!seen[j] && p[j] == -1) {
                p[i] = j+1;
                seen[j] = true;
                bt (j, cur + 1, n, p, seen);
                seen[j] = false;
                p[i] = -1;
            }
        }
        p[i] = -1;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> p (n, -1);
    vector<bool> seen (n, false);
    bt (0, 0, n, p, seen);
}