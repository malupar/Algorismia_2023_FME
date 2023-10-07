#include <iostream>
#include <vector>
using namespace std;
void bt(int k,vector<int>& v,vector<int>& l){
    if(k==v.size()){
        cout<<"(";
        for(int i=0;i<l.size();i++){
            if(i)cout<<',';
            cout<<l[i];
        }
        cout<<")\n";
        return;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=-1){
            l.push_back(v[i]);
            v[i]=-1;
            bt(k+1,v,l);
            v[i]=i+1;
            l.pop_back();
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n),l;
    for(int i=0;i<n;i++)v[i]=i+1;
    bt(0,v,l);
}
