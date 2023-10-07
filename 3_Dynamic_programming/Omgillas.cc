#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,v,t;
    vector<int> c={2,3,5,7,11,13,17,19,23,29};
    int dp[1001][21];
    for(int i=0;i<=1000;i++)for(int j=0;j<20;j++)dp[i][j]=0;
    dp[0][0]=1;
    for(int x:c){
    for(int j=1;j<21;j++){
        for(int i=x;i<=1000;i++)dp[i][j]+=dp[i-x][j-1];
    }
    }
    cin>>t;
    while(t--){
        cin>>n>>v;
        if(v>1000)cout<<0<<'\n';
        else cout<<dp[v][n]<<'\n';
    }
}