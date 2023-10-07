#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e8+7;
typedef vector<int> VI;
typedef vector<VI> VVI;
const int max_n = 3e4+3;
VI dp(max_n), last(max_n);
VI ans(max_n);

int modu(int a, int b) {
    if (a+b > mod) return a+b-mod;
    return a+b;
}

int main() {
    int n;
    dp[1] = 1;
    for (int i = 1; i < max_n; ++i) { // i grupos
        for (int j = i; j+i < max_n; ++j) { // j numeros
            dp[j] = modu(dp[j], last[j-1]);
            if (j-i >= i) dp[j] = modu(dp[j], dp[j-i]);
        }
        for (int j = i; j+i < max_n; ++j) {
            last[j] = dp[j];
            if (i > 1)
                ans[j+i] = modu(ans[j+i], dp[j]);
            dp[j] = 0;
        }
    }
    while (cin >> n) {
        cout << ans[n] << endl;
    }
}