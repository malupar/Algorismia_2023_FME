#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        vector<int> a(n),b(m);
        for(int& i:a)cin>>i;
        for(int& i:b)cin>>i;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+(a[i-1]==b[j-1])));
            }
        }
        cout<<dp[n][m]<<'\n';
    }
}