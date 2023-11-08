#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
map<string,int> m;
map<int,string> mp;
void topsort(vector<vector<int> >& v){
    int n=v.size();
    vector<string> ans;
    vector<int> g(n,0);
    for(int i=0;i<n;i++)for(int x:v[i])g[x]++;
    set<pair<string,int> > s;
    for(int i=0;i<n;i++)if(!g[i])s.insert({mp[i],i});
    while(!s.empty()){
        pair<string,int> y;
        for(auto x:s){
            y=x;
            break;
        }
        s.erase(y);
        ans.push_back(y.first);
        for(int x:v[y.second]){
            g[x]--;
            if(!g[x])s.insert({mp[x],x});
        }
    }
    if(ans.size()!=n)cout<<"NO VALID ORDERING";
    else for(string x:ans)cout<<x;
    cout<<'\n';
}
int main(){
    int n,k;
    string str,str2;
    while(cin>>n){
        vector<vector<int> >v(n,vector<int>());
        for(int i=0;i<n;i++){
            cin>>str;
            m[str]=i;
            mp[i]=str;
        }
        cin>>k;
        while(k--){
            cin>>str>>str2;
            v[m[str]].push_back(m[str2]);
        }
        topsort(v);
    }
}
