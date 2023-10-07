#include <iostream>
#include <vector>
using namespace std;
const int INF=1e6;
int main(){
    int n,m;
    char x;
    while(cin>>n>>m){
        if(!n&&!m)break;
        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>x;
                if(x=='X')continue;
                if(i)dp[i][j]+=dp[i-1][j];
                if(j)dp[i][j]+=dp[i][j-1];
                dp[i][j]=min(dp[i][j],INF);
            }
        }
        if(dp[n-1][m-1]==INF)cout<<"!!!\n";
        else cout<<dp[n-1][m-1]<<'\n';
    }
}