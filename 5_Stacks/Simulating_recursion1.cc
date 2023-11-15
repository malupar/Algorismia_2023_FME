#include <iostream>
#include <stack>
using namespace std;
stack<int> work (int n){
    stack<int> s;
    if(!n)return s;
    s=work(n-1);
    stack<int> st,t;
    t=s;
    while(s.size()){
        st.push(s.top());
        s.pop();
    }
    while(st.size()){
        t.push(st.top());
        st.pop();
    }
    t.push(n);
    return t;
}
int main() {
     int n;
     while (cin >> n) {
         stack<int> s=work(n);
         while(s.size()){
            if(s.size())cout<<' ';
            cout<<s.top();
            s.pop();
         }
         cout << endl;
     }
 }
