#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,t=1,x,y;
    while(cin>>n){
        cout<<'#'<<t<<'\n';
        t++;
        vector<int> v(n+1);
        for(int i=0;i<n;i++){
            cin>>x;
            v[i+1]=v[i]+x;
        }
        cin>>m;
        while(m--){
            cin>>x>>y;
            x--;y--;
            if(x>y)swap(x,y);
            y++;
            cout<<v[y]-v[x]<<'\n';
        }
    }
}
