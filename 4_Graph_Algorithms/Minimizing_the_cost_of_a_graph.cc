#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans,mi,cont;
int find_root(int a,vector<int>& id){
    if(id[a]==a)return a;
    int x=find_root(id[a],id);
    return id[a]=x;
}
void unite(int a,int b,vector<int>& id){
    mi++;
    id[a]=b;
}
void DSU(vector<pair<ll,pair<int,int>> >& v,vector<int>& id,ll n){
    int m=v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
        int a=v[i].second.first,b=v[i].second.second;
        a=find_root(a,id);
        b=find_root(b,id);
        if(a!=b||v[i].first<0){
            unite(a,b,id);
            ans+=v[i].first;
        }
        else if(v[i].first==0)cont++;
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,x,y,w;
    while(cin>>n>>m){
        ans=mi=cont=0;
        vector<int> id(n);
        vector<pair<ll,pair<int,int>> > v;
        for(int i=0;i<n;i++)id[i]=i;
        while(m--){
            cin>>x>>y>>w;
            v.push_back({w,{x,y}});
        }
        DSU(v,id,n);
        cout<<ans<<' '<<mi<<' '<<mi+cont<<'\n';
    }

}
