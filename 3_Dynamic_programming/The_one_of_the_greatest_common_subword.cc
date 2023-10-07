#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s,p;
    while(cin>>s>>p){
        if(s.size()<p.size())swap(s,p);
        int n=s.size(),m=p.size(),sol=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==p[j])dp[i][j]=dp[i+1][j+1]+1;
                else dp[i][j]=0;
                sol=max(sol,dp[i][j]);
            }
        }
        vector<int> best(m);
        vector<char> ans;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)best[i]=max(best[i],dp[j][i]);
        for(int i=0;i<m;i++){
            if(ans.size()<best[i]){
                ans.clear();
                for(int j=i;j<i+best[i];j++){
                    ans.push_back(p[j]);
                }
            }else if(ans.size()==best[i]){
                vector<char> ans2;
                bool ok=false;
                for(int j=i;j<i+best[i];j++){
                    ans2.push_back(p[j]);
                    if(!ok&&p[j]>ans[j-i]){
                        break;
                    }else if(p[j]<ans[j-i])ok=true;
                }
                if(ok)ans=ans2;
            }
        }
        for(auto x:ans)cout<<x;
        cout<<'\n';
    }
}