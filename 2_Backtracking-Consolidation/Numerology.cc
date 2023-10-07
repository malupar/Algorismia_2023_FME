#include <iostream>
#include <vector>
using namespace std;
bool ok;
vector<long long int> pd(15);
void bt(int i,vector<string>& s,string& str,long long int sum,long long int t,long long int res){
    if(i==str.length()&&sum==t){
        ok=true;
        cout<<t<<" = ";
        for(int j=0;j<s.size();j++){
            if(j)cout<<" + ";
            cout<<s[j];
        }
        cout<<'\n';
        return;
    }
    if(i==str.length())return;
    long long int x=0;
    string a="";
    for(int j=i;j<str.length();j++){
        x*=10;
        x+=str[j]-'0';
        a+=str[j];
        res-=(str[j]-'0')*pd[str.length()-j-1];
        if(sum+x<=t&&res+sum+x>=t){
            s.push_back(a);
            bt(j+1,s,str,sum+x,t,res);
            s.pop_back();
        }
        if(sum+x>t)return;
    }
}
int main(){
    long long int n;
    string str;
    while(cin>>n>>str){
        long long int res=0;
        pd[0]=1;
        for(int i=0;i<str.length();i++){
            res*=10;
            pd[i+1]=pd[i]*10;
            res+=str[i]-'0';
        }
        ok=false;
        vector<string> s;
        bt(0,s,str,0,n,res);
        if(!ok)cout<<"No solution for "<<n<<' '<<str<<".\n";
    }
}