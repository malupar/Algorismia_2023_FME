#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool bt(int i,vector<int>& v,int sum,vector<int>& ans,int k){
    if(i==v.size()){
        if(sum==k){
            cout<<'{';
            for(int j=0;j<ans.size();j++){
                if(j)cout<<',';
                cout<<ans[j];
            }
            cout<<"}\n";
            return true;
        }return false;
    }
    ans.push_back(v[i]);
    if(bt(i+1,v,sum+v[i],ans,k))return true;
    ans.pop_back();
    return bt(i+1,v,sum,ans,k);
}
int main(){
    int s,n;
    while(cin>>s>>n){
        vector<int> v(n),ans;
        for(int& i:v)cin>>i;
        sort(v.rbegin(),v.rend());
        if(!bt(0,v,0,ans,s))cout<<"no solution\n";
        break;
    }
}
