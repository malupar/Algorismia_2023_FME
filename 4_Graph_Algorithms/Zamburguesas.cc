#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long double ld;

ld dist(ld x, ld y, ld x2, ld y2) {
    return (x2-x)*(x2-x) + (y2-y)*(y2-y);
}

int main() {
    int n;
    ld d;
    while (cin >> n >> d){
        vector<pair<pair<ld,ld>, ld>> rocks(n);
        for (auto& i: rocks) cin >> i.first.first >> i.first.second >> i.second;
        vector<int> seen(n, 1e9);
        seen[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j = 0; j < n; ++j) {
                ld jump = d+rocks[u].second+rocks[j].second;
                if (dist(rocks[u].first.first, rocks[u].first.second, rocks[j].first.first, rocks[j].first.second) <= jump*jump) {
                    if (seen[j] > seen[u]+1) {
                        seen[j] = seen[u]+1;
                        q.push(j);
                    }
                }
            }
        }
        if (seen[n-1] >= 1e9) cout << "Xof!" << endl;
        else cout << seen[n-1] << endl;
    }
}