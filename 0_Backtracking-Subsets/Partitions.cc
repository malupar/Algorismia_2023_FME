#include <iostream>
#include <vector>
using namespace std;
void bt(int i,int p,vector<string>& word,vector<vector<string>>& ans){
    if(i==word.size()){
        for(int j=0;j<p;j++){
            cout<<"subset "<<j+1<<": {";
            for(int it=0;it<ans[j].size();it++){
                if(it)cout<<',';
                cout<<ans[j][it];
            }
            cout<<"}\n";
        }
        cout<<'\n';
        return;
    }
    for(int j=0;j<p;j++){
        ans[j].push_back(word[i]);
        bt(i+1,p,word,ans);
        ans[j].pop_back();
    }
}
int main(){
    int n,p;
    cin>>n;
    vector<string> word(n);
    for(auto& i:word)cin>>i;
    cin>>p;
    vector<vector<string>> div(p,vector<string>());
    bt(0,p,word,div);
}
