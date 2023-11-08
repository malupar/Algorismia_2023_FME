#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int find_root(int i, VI& id) {
    if (i == id[i]) return i;
    return id[i] = find_root(id[i], id);
}

void merge(int a, int b, VI& id, vector<char>& sz) {
    a = find_root(a, id);
    b = find_root(b, id);
    if (a == b) return;
    if (sz[a] != '.') id[b] = a;
    else id[a] = b;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        VI t(n*m), id(n*m);
        vector<char> sz(n*m, '.');
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                sz[i*m+j] = c;
                id[i*m+j] = i*m+j;

                if (c == '#') {
                    t[i*m+j] = -1;
                    continue;
                }
                if (c != '.') 
                    t[i*m+j] = 1;
                
                if (i && t[i*m+j-m] != -1) {
                    merge(i*m+j, i*m+j-m, id, sz);
                }
                if (j && t[i*m+j-1] != -1) {
                    merge(i*m+j, i*m+j-1, id, sz);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << sz[find_root(i*m+j, id)];
            }
            cout << endl;
        }
        cout << endl;
    }
}