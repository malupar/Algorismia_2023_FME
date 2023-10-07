#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    int n=90,z,o;
    long long dp[n+1][n+1][2][3];
    for(int i=0;i<=n;i++)for(int k=0;k<=n;k++)for(int j=0;j<2;j++)for(int q=0;q<3;q++)dp[i][k][j][q]=0;
    dp[0][0][1][0]=dp[1][0][0][1]=dp[0][1][1][1]=dp[0][2][1][2]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j+1][0][1]=dp[i][j+1][1][1]+dp[i][j+1][1][2];
            dp[i+1][j+1][1][1]=dp[i+1][j][0][1];
            dp[i+1][j+1][1][2]=dp[i+1][j][1][1];
        }
    }
    while(cin>>z>>o){
        cout<<dp[z][o][1][0]+dp[z][o][1][1]+dp[z][o][1][2]+dp[z][o][0][1]<<endl;
    }
}