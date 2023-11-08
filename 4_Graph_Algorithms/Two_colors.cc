#include <iostream>
#include <vector>
using namespace std;
int ok;
void dfs(int a,vector<vector<int> >& v,vector<int>& c){
	for(int x:v[a]){
		if(c[x]==-1){
			c[x]=1-c[a];
			dfs(x,v,c);
			if(!ok)return;
		}
		else if(c[x]==c[a]){
			ok=false;
			return;
		}
	}
}
int main(){
	int n,m,x,y;
	while(cin>>n>>m){
		ok=true;
		vector<vector<int> >v(n,vector<int>());
		vector<int> c(n,-1);
		while(m--){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=0;i<n;i++){
			if(c[i]==-1){
			    c[i]=0;
			    dfs(i,v,c);
			}
		}
		if(ok)cout<<"yes\n";
		else cout<<"no\n";
	}
}