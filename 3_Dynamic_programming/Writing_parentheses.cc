#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<unsigned long long int> dp(34);
    dp[0]=dp[1]=1;
    for(int i=2;i<34;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    while(cin>>n){
        if(n&1)cout<<0<<'\n';
        else cout<<dp[n/2]<<'\n';
    }
}