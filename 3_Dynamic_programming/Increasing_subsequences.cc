#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        vector<int> dp(26);
        for(int i=0;i<s.size();i++){
            int ans=0;
            for(int j=0;j<s[i]-'a';++j){
                ans+=dp[j];
            }
            dp[s[i]-'a']+=ans+1;
        }
        int ans=-s.size();
        for(int i=0;i<26;i++)ans+=dp[i];
        cout<<ans<<'\n';
    }
}