#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int cont,vector<int>& v,vector<int>& l,int t,int p){
    if(cont==t&&p){
        cout<<"{";
        for(int i=0;i<l.size();i++){
            if(i)cout<<',';
            cout<<l[i];
        }
        cout<<"}\n";
    }
    if(i<v.size()){
        l.push_back(v[i]);
        bt(i+1,cont+v[i],v,l,t,1);
        l.pop_back();
    }
    if(i<v.size())bt(i+1,cont,v,l,t,0);
}
int main(){
    int n,m;
    cin>>m>>n;
    vector<int> v(n),sum(n+1),l;
    sum[n]=0;
    for(int i=0;i<n;i++)cin>>v[i];
    bt(0,0,v,l,m,1);
}