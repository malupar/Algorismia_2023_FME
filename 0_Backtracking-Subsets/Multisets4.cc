#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int n,int cnt,int x,int t,vector<int>& v){
    if(cnt>t)return;
    if(cnt==t){
        bool first=false;
        cout<<'{';
        for(int num=0;num<n;num++){
            for(int j=0;j<v[num];j++){
            if(!first)first=true;
            else cout<<',';
            cout<<num+1;
            }
        }
        cout<<"}\n";
        return;
    }
    if(i>n)return;
    if((n-i+1)*x+cnt<t)return;
    int dif=t-cnt;
    bt(i+1,n,cnt,x,t,v);
    for(int j=0;j<min(x,dif);j++){
        v[i-1]++;
        bt(i+1,n,cnt+j+1,x,t,v);
    }
    v[i-1]-=min(dif,x);
}
int main(){
    int n,x,y,t;
    cin>>n>>x>>y>>t;
    vector<int> v;
    for(int i=0;i<n;i++)v.push_back(x);
    bt(1,n,n*x,y-x,t,v);
}
