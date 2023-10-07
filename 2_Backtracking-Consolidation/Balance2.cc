#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
void bt(int i,int n,int pl, int pr, vector<int>& w, vector<int>& used){
    if (i == n) {
        ++ans;
        return;
    }
    for (int j = 0; j <n; ++j) {
        if (used[j]) continue;
        used[j] = 1;
        bt(i+1,n,pl+w[j], pr,w, used);
        if (pr+w[j]<=pl) bt(i+1,n,pl,pr+w[j],w, used);
        used[j] = 0;
    }
}
int main(){
    int n;
    while(cin >> n) {
        ans = 0;
        vector<int> w(n), used(n);
        for(int i=0;i<n;i++)cin>>w[i];
        bt(0,n,0,0,w, used);
        cout<<ans<<endl;
    }
}