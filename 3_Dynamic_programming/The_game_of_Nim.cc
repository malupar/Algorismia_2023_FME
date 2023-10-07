#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    string str,str2;
    cin>>t;
    for(int j=1;j<=t;j++){
        cin>>str>>str2;
        vector<int> v(6);
        for(int i=0;i<6;i++)cin>>v[i];
        int ans=0;
        for(int i=0;i<6;i++)ans^=v[i];
        cout<<"Game #"<<j<<": ";
        if(ans)cout<<str<<'\n';
        else cout<<str2<<'\n';
    }
}