#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    int n,m,x,y,w;
    while(cin>>n>>m){
        vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>());
        vector<ll> dist(n,1e18);
        vector<int> par(n);
        while(m--){
            cin>>x>>y>>w;
            g[x].push_back({y,w});
        }
        cin>>x>>y;
        dist[x]=0;
        par[x]=-1;
        priority_queue<pair<int,int>> pq;
        pq.push({0,x});
        while(!pq.empty()){
            int d=-pq.top().first,u=pq.top().second;
            pq.pop();
            if(d>dist[u])continue;
            for(auto v:g[u]){
                if(dist[v.first]>d+v.second){
                    par[v.first]=u;
                    dist[v.first]=d+v.second;
                    pq.push({-dist[v.first],v.first});
                }
            }
        }
        if(dist[y]==1e18)cout<<"no path from "<<x<<" to "<<y<<"\n";
        else {
            vector<int> ans;
            while(y!=-1){
                ans.push_back(y);
                y=par[y];
            }
            for(int i=ans.size()-1;i>=0;i--){
                cout<<ans[i];
                if(i)cout<<' ';
            }
            cout<<'\n';
        }
    }
}