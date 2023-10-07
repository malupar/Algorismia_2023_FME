#include <iostream>
#include <vector>
using namespace std;
int main(){
    int max_n=5e5+3,n;
    vector<int> v(max_n);
    for(int i=0;i<max_n;i++)v[i]=i;
    for(int i=0;i<max_n-8;i++){
        v[i+5]=min(v[i]+1,v[i+5]);
    }
    for(int i=0;i<max_n-8;i++){
        v[i+8]=min(v[i]+1,v[i+8]);
    }
    for(int i=0;i<max_n-14;i++){
        v[i+14]=min(v[i]+1,v[i+14]);
    }
    while(cin>>n){
        if(n==-1)break;
        cout<<v[n]<<'\n';
    }
}
