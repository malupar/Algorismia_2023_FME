#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> pii;
int n, m;
VI seen;
VVI v;
bool ok,ok2;
void OK1(int a) {
  for(int x:v[a]){
    if(seen[x]==-1){
        seen[x]=1-seen[a];
        OK1(x);
    }
    if(seen[x]==seen[a])ok2=false;
  }
}
int main() {
  while (cin >> n >> m) {
    ok=ok2=true;
    v=VVI(n,VI());
    seen=VI (n,-1);
    while (m--) {
      int x, y;
      cin >> x >> y;
      v[y].push_back(x);
      v[x].push_back(y);
    }
    seen[0]=0;
    OK1(0);
    for(int i=0;i<n;i++)if(seen[i]==-1)ok=false;
    if(!ok)cout<<"NC\n";
    else if(ok2)cout<<"yes\n";
    else cout<<"no\n";
  }
}
