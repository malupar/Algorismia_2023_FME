#include <iostream>
#include <vector>
using namespace std;
//#define int long long int
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int find_root(int a,vector<int>& id){
    if(id[a]==a)return a;
    return id[a]=find_root(id[a],id);
}
void unite(int a,int b,vector<int>& id,vector<int>& sz){
    a=find_root(a,id),b=find_root(b,id);
    if(a==b)return;
    id[a]=b;
    sz[b]+=sz[a];
}
signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int max_n=1e5+2;
    vector<int> seen(max_n,-1);
    for(long long int i=2;i<max_n;i++){
        if(seen[i]==-1){
            //cout<<i<<' ';
            seen[i]=i;
            for(long long int j=i;j*i<max_n;j++)if(seen[j*i]==-1)seen[j*i]=i;
        }
    }
    int n;
    while(cin>>n){
        vector<int> fam(max_n,-1);
        vector<int> v(n),id(n),sz(n,1);
        for(int i=0;i<n;i++){
            cin>>v[i];
            id[i]=i;
        }
        for(int i=0;i<n;i++){
            while(v[i]!=1){
                if(fam[seen[v[i]]]!=-1)unite(fam[seen[v[i]]],i,id,sz);
                else fam[seen[v[i]]]=i;
                v[i]/=seen[v[i]];
            }
        }
        int ans=1;
        for(int i=0;i<n;i++)ans=max(ans,sz[i]);
        cout<<ans<<'\n';
    }
}
