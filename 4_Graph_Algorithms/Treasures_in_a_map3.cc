#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int find_root(int i, VI& id) {
    if (i == id[i]) return i;
    return id[i] = find_root(id[i], id);
}

void merge(int a, int b, VI& id, VI& sz) {
    a = find_root(a, id);
    b = find_root(b, id);
    if (a == b) return;
    sz[a] += sz[b];
    id[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;
    VI t(n*m), id(n*m), sz(n*m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            id[i*m+j] = i*m+j;
            if (c == 'X') {
                t[i*m+j]=-1;
                continue;
            }
            if (c == 't') t[i*m+j] = sz[i*m+j] = 1;
            if (i && t[i*m+j-m] != -1) {
                merge(i*m+j, i*m+j-m, id, sz);
            }
            if (j && t[i*m+j-1] != -1) {
                merge(i*m+j, i*m+j-1, id, sz);
            }
        }
    }
    int x, y;
    cin >> x >> y;
    --x;--y;
    cout << sz[find_root(x*m+y, id)] << endl;
}