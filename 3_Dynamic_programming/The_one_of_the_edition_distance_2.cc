#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> c (n);
        int mi = 1e9;
        for (int& i:c) {
            cin >> i;
            mi = min(mi, i);
        }
        vector<int> in_cost (n);
        for (int i = 0; i < n; ++i) in_cost[i] = min(c[i], mi + int(ceil((double(mi) + c[i])/4)));
        string s, t;
        cin >> s >> t;
        int m1 = s.size(), m2 = t.size();
        int dp[m1+1][m2+1];
        for (int i = 0; i <= m1; ++i) {
            for (int j = 0; j <= m2; ++j) dp[i][j] = 1e9;
        }
        dp[0][0] = 0;

        for (int i = 0; i <= m1; ++i) {
            for (int j = 0; j <= m2; ++j) {
                if (i) {
                    dp[i][j] = min (dp[i][j], dp[i-1][j] + in_cost[s[i-1]-'a']);
                }
                if (j) {
                    dp[i][j] = min (dp[i][j], dp[i][j-1] + in_cost[t[j-1]-'a']);
                }
                if (i && j) {
                    if (s[i-1] == t[j-1]) dp[i][j] = min (dp[i][j], dp[i-1][j-1]);
                    else dp[i][j] = min (dp[i][j], dp[i-1][j-1] + int(ceil((double(c[s[i-1]-'a']) + c[t[j-1]-'a'])/4)));
                }
            }
        }
        cout << dp[m1][m2] << endl;
    }
}