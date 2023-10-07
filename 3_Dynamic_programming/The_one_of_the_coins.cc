#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,t;
    while(cin>>n){
        vector<int> v(n);
        for(int& i:v)cin>>i;
        sort(v.rbegin(),v.rend());
        cin>>t;
        vector<int> dp(t+1);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=v[i];j<=t;j++)if(dp[j-v[i]])dp[j]=max(dp[j],dp[j-v[i]]+1);
        }
        if(!dp[t])cout<<-1<<'\n';
        else{
            int to=t,j=0;
            vector<int> ans;
            while(to!=0){
                if(to>=v[j]&&dp[to-v[j]]){
                    ans.push_back(v[j]);
                    to-=v[j];
                }else j++;
            }
            for(int i=0;i<ans.size();i++){
                if(i)cout<<',';
                cout<<ans[i];
            }
            cout<<'\n';
        }
    }
}