#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int max_n=1e5+4;
vector<int> id(max_n);
long long int ans;
int find_root(int a){
	if(id[a]==a)return a;
	return id[a]=find_root(id[a]);
}
void solve(vector<pair<int,pair<int,int> > >& v){
	int m=v.size();
	for(int i=0;i<m;i++){
		int a=find_root(v[i].second.first),b=find_root(v[i].second.second);
		if(a!=b){
			ans+=v[i].first;
			id[a]=b;
		}
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		ans=0;
		for(int i=1;i<=n;i++)id[i]=i;
		vector<pair<int,pair<int,int> > >v(m);
		for(int i=0;i<m;i++)cin>>v[i].second.first>>v[i].second.second>>v[i].first;
		sort(v.begin(),v.end());
		solve(v);
		cout<<ans<<'\n';
	}
}
