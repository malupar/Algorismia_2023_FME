#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    string s,p;
    while(cin>>n){
        vector<int> l(n);
        for(int& i:l)cin>>i;
        cin>>s>>p;
        int a=s.size(),b=p.size();
        vector<vector<int>> dp(a+1,vector<int>(b+1));
        for(int i=0;i<a;i++){
            dp[i+1][0]=dp[i][0]+l[s[i]-'a'];
        }
        for(int j=0;j<b;j++){
            dp[0][j+1]=dp[0][j]+l[p[j]-'a'];
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                dp[i+1][j+1]=min(dp[i][j+1]+l[s[i]-'a'],dp[i+1][j]+l[p[j]-'a']);
                if(s[i]==p[j])dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            }
        }
        cout<<dp[a][b]<<'\n';
    }
}