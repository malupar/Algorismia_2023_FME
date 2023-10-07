#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

VVI dist_num;
VVI comb_num;

ll CN(int i, int j) {
    if (j < 0 || i < 0) return 0;
    if (i == j) return 1;
    if (!j) return 1;
    if (comb_num[i][j] != -1) return comb_num[i][j];
    return comb_num[i][j] = (CN(i-1, j-1)+CN(i-1, j));
}

ll dist(int n, int y) {
    if (n < 0 || y < 0) return 0;
    if (n < y) return 0;
    if (n == y) return 1;
    if (!y) return 0;
    if (dist_num[n][y] != -1) return dist_num[n][y];
    return dist_num[n][y] = y*dist(n-1, y)+dist(n-1,y-1);
}

ll DP(int n, int x, int y) {
    return CN(n, y)*dist(n-y, x);
}

int main() {
    int n, x, y;
    comb_num = VVI(26, VI(26, -1));
    dist_num = VVI(26, VI(26, -1));
    while (cin >> n >> x >> y) {
        cout << DP(n, x, y) << endl;
    }
}