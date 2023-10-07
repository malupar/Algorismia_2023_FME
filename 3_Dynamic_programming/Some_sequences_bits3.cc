#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    int n=30,z,o;
    long long dp[n+1][n+1][2][3];
    for(int i=0;i<=n;i++)for(int k=0;k<=n;k++)for(int j=0;j<2;j++)for(int q=0;q<3;q++)dp[i][k][j][q]=0;
    dp[0][0][0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i){
                dp[i][j][0][0]=dp[i-1][j][0][0]+dp[i-1][j][1][0];
                dp[i][j][0][1]=dp[i-1][j][0][1]+dp[i-1][j][1][1];
                dp[i][j][0][2]=dp[i-1][j][0][2]+dp[i-1][j][1][2];
            }
            if(j){
                if((i+j)&1)dp[i][j][1][0]=dp[i][j-1][0][2]+dp[i][j-1][1][2];
                else dp[i][j][1][0]=dp[i][j-1][0][1]+dp[i][j-1][1][1];
                if((i+j)&1)dp[i][j][1][1]=dp[i][j-1][0][0]+dp[i][j-1][1][0];
                else dp[i][j][1][1]=dp[i][j-1][0][2]+dp[i][j-1][1][2];
                if((i+j)&1)dp[i][j][1][2]=dp[i][j-1][0][1]+dp[i][j-1][1][1];
                else dp[i][j][1][2]=dp[i][j-1][0][0]+dp[i][j-1][1][0];
            }
        }
    }
    while(cin>>z>>o){
        cout<<dp[z][o][0][0]+dp[z][o][1][0]<<endl;
    }
}