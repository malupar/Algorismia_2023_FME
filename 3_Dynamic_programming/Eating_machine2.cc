#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

const int mod = 1e8+7;

VVVI dp;
VVI comb_num;

int CN(int i, int j) {
    if (i == j) return 1;
    if (!j) return 1;
    if (comb_num[i][j] != -1) return comb_num[i][j];
    return comb_num[i][j] = (CN(i-1, j-1)+CN(i-1, j))%mod;
}

int DP(int num_tartas, int rep_tartas, int come){
    if (rep_tartas < 0 || num_tartas < 0 || come < 0) return 0;
    if (dp[num_tartas][rep_tartas][come] != -1) return dp[num_tartas][rep_tartas][come];
    if (!num_tartas && come) return 0;
    if (!num_tartas && rep_tartas) return 0;
    if (!come) return 0;
    int ans = (1ll*DP(num_tartas-1, rep_tartas, come-1)*CN(come, come-1))%mod;
    for (int j = 2; j <= come; ++j) {
        ans = (ans+(1ll*DP(num_tartas-1, rep_tartas-1, come-j)*CN(come, j))%mod)%mod;
    }
     //cout << num_tartas << ' ' << rep_tartas << ' ' << come << ' ' << ans << '\n';
    return dp[num_tartas][rep_tartas][come] = ans;
}

int main() {
    int n, c;
    dp = VVVI(81, VVI(81, VI(81, -1))); //Numero de maneras que hay para las i primeras tartas, j repetidas y k comilonas
    comb_num = VVI(200, VI(200, -1));
    dp[0][0][0] = 1;
    while (cin >> n >> c) {
        int ans = 0;
        for (int i = c/2+c%2; i <= c; ++i) {
            ans = (ans+DP(c, i, n))%mod;
        }
        cout << ans << endl;
    }
}