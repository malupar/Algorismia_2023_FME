#include <iostream>
#include <vector>
using namespace std;
bool primera=true;
void bt(int i,vector<string>& l, vector<string>& v) {
    if (i==v.size()) {
        if(primera) cout<<"{}"<<'\n',primera=false;
        else{
            cout<<"{"<<l[0];
            for (int j=1;j<(int)l.size();j++)cout<<","<<l[j];
            cout << "}\n";
        }
        return;
    }
    bt(i+1,l,v);
    l.push_back(v[i]);
    bt(i+1,l,v);
    l.pop_back();
}
int main(){
	int n;
	cin>>n;
	vector <string> v(n);
	vector <string> l;
	for(int i=0;i<n;i++)cin>>v[i];
	bt(0,l,v);
}