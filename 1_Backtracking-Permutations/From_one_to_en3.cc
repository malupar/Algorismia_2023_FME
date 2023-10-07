#include <iostream>
#include <vector>

using namespace std;

void bt (int i, int n, int k, vector<int>& cur, vector<bool>& seen) {
    //cout << i << ' ';
    if (i == n and !k) {
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ',';
            cout << cur[i];
        }
        cout << ")\n";
    }
    else {
        int dif = n-i;
        if (dif*(dif-1)/2 < k) return;
        int cnt = n-i-1;
        int last = k-(dif-2)*(dif-1)/2;
        //cout << last << ' ';
        for (int j = n-1; j >= 0; --j) {
            if (!seen[j] and k >= cnt) {
                seen[j] = true;
                cur.push_back (j+1);
                bt (i+1, n, k - cnt, cur, seen);
                cur.pop_back();
                seen[j] = false;
            }
            if (!seen[j]) --cnt;
            if (last > cnt) return;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cur;
    vector<bool> seen (n, false);
    bt (0, n, k, cur, seen);
}
