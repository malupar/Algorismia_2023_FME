#include <iostream>
#include <vector>
using namespace std;
void bt(int i,vector<string>& v,vector<string>& l,int k){
    if(l.size()==k){
        cout<<"{";
        for(int i=0;i<l.size();i++){
            if(i)cout<<',';
            cout<<l[i];
        }
        cout<<"}\n";
        return;
    }
    l.push_back(v[i]);
    bt(i+1,v,l,k);
    l.pop_back();
    if(k-l.size()<v.size()-i)bt(i+1,v,l,k);

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v(m),l;
    for(int i=0;i<m;i++)cin>>v[i];
    bt(0,v,l,n);
}
