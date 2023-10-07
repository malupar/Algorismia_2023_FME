#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int n,int x,vector<int>& v){
    if(i>n){
        cout<<'{';
        for(int j=0;j<v.size();j++){
            if(j)cout<<',';
            cout<<v[j];
        }
        cout<<"}\n";
        return;
    }
    for(int j=0;j<=x;j++){
        bt(i+1,n,x,v);
        v.push_back(i);
    }
    for(int j=0;j<=x;j++)v.pop_back();
}
int main(){
    int n,x;
    while(cin>>n>>x){
        vector<int> v;
        bt(1,n,x,v);
    }
}