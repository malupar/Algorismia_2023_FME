#include <iostream>
#include <vector>
using namespace std;
void bt(int o,int z,vector<int>& num){
    if(!o&&!z){
        for(int i=0;i<num.size();i++){
            if(i)cout<<' ';
            cout<<num[i];
        }
        cout<<'\n';
    }else{
        if(z){
            num.push_back(0);
            bt(o,z-1,num);
            num.pop_back();
        }
        if(o){
            num.push_back(1);
            bt(o-1,z,num);
            num.pop_back();
        }
    }
}
int main(){
    int n,z;
    while(cin>>n>>z){
        vector<int> num;
        bt(z,n-z,num);
    }
}