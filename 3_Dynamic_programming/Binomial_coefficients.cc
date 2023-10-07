#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll inv(ll n,ll k){
    if(!k)return 1;
    ll x=inv(n,k/2);
    if(k&1)return(((x*x)%mod)*n%mod);
    return (x*x)%mod;
}
int main(){
    int max_n=31,n,k;
    vector<ll> f(31);
    f[0]=1;
    for(int i=1;i<max_n;i++)f[i]=(1LL*f[i-1]*i)%mod;
    while(cin>>n>>k){
        cout<<((f[n]*inv(f[n-k],mod-2))%mod*inv(f[k],mod-2))%mod<<'\n';
    }
}
