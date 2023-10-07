#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;

VI dp;

int DP(int i, int m) {
    if (!i) return 0;
    if (i == 1) return dp[i] = m;
    if (dp[i] != -1) return dp[i];
    int ans = DP(i-2, m);
    for (int j = 1; j+5 < i; j += 2) {
        ans += DP(j, m)*DP(i-j-5,m);
    }
    return dp[i] = ans;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        dp = VI(n+1, -1);
        cout << DP(n, m) << endl;
    }
}