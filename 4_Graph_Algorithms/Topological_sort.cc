#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void topsort(vector<vector<int> >& v){
	int n=v.size();
	vector<int> g(n,0);
	vector<int> ans;
	priority_queue<int> q;
	for(int i=0;i<n;i++){
		for(int x:v[i])g[x]++;
	}
	for(int i=0;i<n;i++)if(!g[i])q.push(-i);
	while(!q.empty()){
		int u=-q.top();
		ans.push_back(u);
		q.pop();
		for(int x:v[u]){
			g[x]--;
			if(!g[x])q.push(-x);
		}
	}
	for(int i=0;i<n;i++){
		if(i)cout<<' ';
		cout<<ans[i];
	}
	cout<<'\n';
}
int main(){
	int n,m,x,y;
	while(cin>>n>>m){
		vector<vector<int> >v(n,vector<int>());
		while(m--){
			cin>>x>>y;
			v[x].push_back(y);
		}
		topsort(v);
	}
}
