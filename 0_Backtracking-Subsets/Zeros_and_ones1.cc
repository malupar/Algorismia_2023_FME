#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        int x=i;
        stack<int> s;
        while(x){
            if(x&1)s.push(1);
            else s.push(0);
            x>>=1;
        }
        if(s.empty()){
            for(int j=0;j<n-1;j++)cout<<0<<' ';
            cout<<0;
        }
        else for(int j=(int)s.size();j<n;j++)cout<<0<<' ';
        while(!s.empty()){
            cout<<s.top();
            s.pop();
            if(!s.empty())cout<<' ';
        }
        cout<<'\n';
    }
}