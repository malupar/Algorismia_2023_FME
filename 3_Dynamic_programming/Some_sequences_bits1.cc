#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    int n=150,x;
    long long dp[n+1][2][3];
    for(int i=0;i<=n;i++)for(int j=0;j<2;j++)for(int q=0;q<3;q++)dp[i][j][q]=0;
    dp[0][0][0]=dp[0][1][0]=1;
    for(int i=0;i<n;i++){
        dp[i+1][0][1]=dp[i][1][0]+dp[i][1][1]+dp[i][1][2];
        dp[i+1][1][1]=dp[i][0][0]+dp[i][0][1]+dp[i][0][2];
        dp[i+1][1][2]=dp[i][1][1];
    }
    while(cin>>x){
        cout<<dp[x][1][0]+dp[x][1][1]+dp[x][1][2]+dp[x][0][1]<<endl;
    }
}
