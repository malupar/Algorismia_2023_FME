#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int n,int x,vector<int>& v){
    if(v.size()==x){
        cout<<'{';
        for(int j=0;j<x;j++){
            if(j)cout<<',';
            cout<<v[j];
        }
        cout<<"}\n";
        return;
    }
    if(i>n)return;
    int cnt=v.size();
    for(int j=cnt;j<x;j++)v.push_back(i);
    for(int j=cnt;j<x;j++){
        bt(i+1,n,x,v);
        v.pop_back();
    }
    bt(i+1,n,x,v);
}
int main(){
    int n,x;
    while(cin>>n>>x){
        vector<int> v;
        bt(1,n,x,v);
    }
}
