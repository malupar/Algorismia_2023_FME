#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    string s;
    while(getline(cin,s)){
        string x;
        vector<string> y;
        stack <string> e;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(x=="")continue;
                e.push(x);
                y.push_back(x);
                x="";
            }
            else x+=s[i];
        }
        if(x!=""){
            e.push(x);
        }
        bool ok=true;
        for(int i=0;i<y.size();i++){
            if(e.top()!=y[i])ok=false;
            e.pop();
        }
        if(ok)cout<<"It is a palindrome.\n";
        else cout<<"It is NOT a palindrome.\n";
    }
}
