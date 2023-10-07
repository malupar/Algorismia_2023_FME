#include <iostream>
#include <vector>
using namespace std;
int main(){
    int grid[500][500],cont=0;
    for(int i=0;i<500;i++)for(int j=0;j<500;j++)grid[i][j]=0;
    string str;
    while(cin>>str){
        int n=str.length();
        for(int i=0;i<n;i++){
            if(cont)grid[cont][i]+=grid[cont-1][i];
            if(i)grid[cont][i]+=grid[cont][i-1];
            if(i&&cont)grid[cont][i]-=grid[cont-1][i-1];
            int x=str[i]-'A'+1;
            grid[cont][i]+=x*(x+1)/2;
            if(i)cout<<' ';
            cout<<grid[cont][i];
        }
        cont++;
        cout<<'\n';
    }
}