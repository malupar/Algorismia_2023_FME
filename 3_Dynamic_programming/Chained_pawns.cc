#include <iostream>
using namespace std;
int main(){
	int r,c;
	while(cin>>r>>c){
		long long int grid[r][c];
		for(int i=0;i<r;i++)for(int j=0;j<c;j++)grid[i][j]=0;
		for(int i=0;i<c;i++)grid[0][i]=1;
		for(int i=0;i<r-1;i++){
			for(int j=0;j<c;j++){
				if(j)grid[i+1][j-1]+=grid[i][j];
				if(c-j-1>0)grid[i+1][j+1]+=grid[i][j];
			}
		}
		long long int ans=0;
		for(int i=0;i<c;i++)ans+=grid[r-1][i];
		cout<<ans<<'\n';
	}
}
