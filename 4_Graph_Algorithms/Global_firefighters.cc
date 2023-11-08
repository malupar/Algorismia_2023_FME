#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int t,n,m,x,y,w,k,q;
    cin>>t;
    for(int test=0;test<t;test++){
        if(test)cout<<'\n';
        cout<<"Case #"<<test+1<<'\n';
        cin>>n>>m;
        vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>());
        vector<long long> dist(n,1e18),par(n);
        while(m--){
            cin>>x>>y>>w;
            g[x].push_back({y,w});
            g[y].push_back({x,w});
        }
        cin>>k;
        priority_queue<pair<long long,pair<int,int>>> pq;
        while(k--){
            cin>>x;
            pq.push({0,{x,x}});
            dist[x]=0;
            par[x]=x;
        }
        while(pq.size()){
            long long d=-pq.top().first,u=pq.top().second.second;
            //cout<<d<<' '<<u<<'\n';
            pq.pop();
            if(d>dist[u])continue;
            for(auto v:g[u]){
                //cout<<"ok ";
                if(dist[v.first]>d+v.second){
                    dist[v.first]=d+v.second;
                    par[v.first]=par[u];
                    pq.push({-dist[v.first],{par[v.first],v.first}});
                }else if(dist[v.first]==d+v.second&&par[v.first]>par[u]){
                    dist[v.first]=d+v.second;
                    par[v.first]=par[u];
                    pq.push({-dist[v.first],{par[v.first],v.first}});
                }
            }
        }
        cin>>q;
        while(q--){
            cin>>x;
            cout<<"To get to "<<x<<", distance "<<dist[x]<<", from city "<<par[x]<<".\n";
        }
    }
}