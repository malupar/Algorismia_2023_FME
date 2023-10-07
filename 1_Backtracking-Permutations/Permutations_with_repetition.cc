#include <iostream>
#include <vector>

using namespace std;

void bt (int n, vector<string>& v, vector<string>& cur) {
    if (cur.size() == n) {
        cout << '(';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ',';
            cout << cur[i];
        }
        cout << ")\n";

    }else {
        for (int i = 0; i < n; ++i) {
            cur.push_back (v[i]);
            bt (n, v, cur);
            cur.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> st (n), cur;
    for (auto& i : st) cin >> i;

    bt (n, st, cur);
}