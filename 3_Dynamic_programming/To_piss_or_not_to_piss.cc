#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
VVI dp;

int DP(int n, int k) { //how many people are needed for n toilets and k doors
    if (!k) {
        if (n <= 5) return dp[n][k] = n/2+n%2;
        else return dp[n][0] = dp[n/2+n%2][0]+dp[n/2][0]-1;
    }
    if (n < k) return 0;
    if (n == k+1) return n;
    if (dp[n][k] != -1) return dp[n][k];
    int ans = 0;
    for (int j = 1; j < n; ++j) {
        //cout << DP(j, 0) << ' ' << DP(n-j, k-1) << ' ' << j << endl;
        ans = max(ans, DP(j, 0)+DP(n-j, k-1));
    }
    return dp[n][k] = ans;
}

int main() {
    int n, p;
    dp = VVI(501, VI(501, -1));
    for (int i = 1; i <= 500; ++i) {
        if (i < 6) dp[i][0] = i/2+i%2;
        else dp[i][0] = dp[i/2+i%2][0]+dp[i/2+1][0]-1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = 0;
            for (int k = 1; k < i; ++k) {
                dp[i][j] = max(dp[k][0]+dp[i-k][j-1], dp[i][j]);
            }
        }
    }
    while (cin >> n >> p) {
        for (int j=0; j < n; ++j) {
            if (dp[n][j]*100 >= p*n) {
                //cout << DP(n, j) << ' ';
                cout << j << endl;
                break;
            }
        }
    }
}