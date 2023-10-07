#include <iostream>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        int dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) dp[i][j] = 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n-i; ++j) {
                dp[j][j+i] = min (dp[j][j+i-1], dp[j+1][j+i]) + 1;
                if (s[j] == s[j+i]) dp[j][j+i] = min (dp[j][j+i], dp[j+1][j+i-1]);
            }
        }
        if (!dp[0][n-1]) cout << "Passes the Dislex-Wonga test" << endl;
        else cout << dp[0][n-1] << endl;
    }
}
