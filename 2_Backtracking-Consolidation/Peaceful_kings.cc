#include <iostream>
#include <vector>
using namespace std;
bool check(int x,int n,vector<int>& g){
    if(x%n&&g[x-1])return false;
    if(x%n&&x>=n&&g[x-n-1])return false;
    if(x>=n&&g[x-n])return false;
    if(x%n&&x<(n-1)*n&&g[x+n-1])return false;
    if(n-(x%n)-1&&g[x+1])return false;
    if(n-(x%n)-1&&x>=n&&g[x-n+1])return false;
    if((x<(n-1)*n)&&g[x+n])return false;
    if(n-(x%n)-1&&x<(n-1)*n&&g[x+n+1])return false;
    return true;
}
void print(int n,int k,vector<int>& g,int cont,int last){
    if(k==cont){
    for(int i=0;i<n*n;i++){
        if(g[i])cout<<'K';
        else cout<<'.';
        if((i+1)%n==0)cout<<endl;
    }
    cout<<"----------"<<endl;
    return;
    }
        for(int i=last;i<n*n;i++){
            if(!g[i]){
                if(check(i,n,g)){
                    g[i]=1;
                    print(n,k,g,cont+1,i+1);
                    g[i]=0;
                }
            }
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n*n,0);
    print(n,k,v,0,0);
}