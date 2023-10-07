#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int cont,vector<int>& v,vector<int>& sum,vector<int>& l,int t,int p){
    if(cont==t&&p){
        cout<<"{";
        for(int i=0;i<l.size();i++){
            if(i)cout<<',';
            cout<<l[i];
        }
        cout<<"}\n";
    }
    if(cont+v[i]<=t&&i<v.size()){
        l.push_back(v[i]);
        bt(i+1,cont+v[i],v,sum,l,t,1);
        l.pop_back();
    }
    if(sum[i+1]+cont>=t&&i<v.size())bt(i+1,cont,v,sum,l,t,0);
}
int main(){
    int n,m;
    cin>>m>>n;
    vector<int> v(n),sum(n+1),l;
    sum[n]=0;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=n-1;i>=0;i--){
        sum[i]=sum[i+1]+v[i];
    }
    bt(0,0,v,sum,l,m,1);
}
