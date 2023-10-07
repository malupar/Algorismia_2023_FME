#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int t,vector<int>& v,int cont,vector<int>& l){
    if(cont==t){
        for(int i=0;i<l.size();i++){
            if(i)cout<<' ';
            cout<<l[i];
        }
        cout<<endl;
        return;
    }
    if(i==v.size())return;
    if(v[i]+cont<=t){
        l.push_back(v[i]);
        bt(i,t,v,cont+v[i],l);
        l.pop_back();
    }
    bt(i+1,t,v,cont,l);
}
int main(){
    int n;
    vector<int> v={50,20,10,5,2,1},l;
    while(cin>>n){
        bt(0,n,v,0,l);
        cout<<endl;
    }
}
