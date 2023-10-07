#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,c,x,ans=-1,ro,co;
    cin>>n>>m>>c;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+x;
        }
    }
    for(int i=c;i<=n;i++){
        for(int j=c;j<=m;j++){
            if(ans<dp[i][j]-dp[i][j-c]-dp[i-c][j]+dp[i-c][j-c]){
                ans=dp[i][j]-dp[i][j-c]-dp[i-c][j]+dp[i-c][j-c];
                ro=i-c;co=j-c;
            }
        }
    }
    cout<<ro<<' '<<co<<endl;
}
