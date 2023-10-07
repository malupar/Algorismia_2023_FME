#include <iostream>
#include <vector>
using namespace std;
int main(){
    int r,c;
    while(cin>>c>>r){
        vector<vector<char>> grid(r,vector<char>(c));
        vector<vector<int>> dp(r,vector<int> (c,1e9));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)cin>>grid[i][j];
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='M')dp[i][j]=0;
                if(grid[i][j]=='*')continue;
                if(i){
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+3*(grid[i][j]=='T'));
                    if(j)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1+3*(grid[i][j]=='T'));
                    if(j<c-1)dp[i][j]=min(dp[i][j],dp[i-1][j+1]+1+3*(grid[i][j]=='T'));
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<c;i++){
            if(grid[r-1][i]=='*')continue;
            ans=min(ans,dp[r-1][i]);
        }
        if(ans==1e9)cout<<"IMPOSSIBLE\n";
        else cout<<ans<<'\n';
        break;
    }
}
