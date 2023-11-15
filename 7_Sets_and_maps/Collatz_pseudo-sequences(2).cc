#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        map<int, int> mp;
        int cnt = 1;
        while (n <= INF) {
            mp[n] = cnt;
            if (n%2 == 0) n = n/2 + x;
            else n = 3*n + y;
            if (mp.find(n) != mp.end()) {
                break;
            }
            ++cnt;
        }
        if (n > INF) cout << n << endl;
        else cout << cnt-mp[n]+1 << endl;
    }
}