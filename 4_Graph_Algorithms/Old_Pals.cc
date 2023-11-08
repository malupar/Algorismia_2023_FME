#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

stack<int> st;
void dfs(int u, vector<vector<int>>& g, vector<int>& seen) {
    seen[u] = 1;
    for (int v: g[u]) {
        if (!seen[v]) {
            dfs(v, g, seen);
        }
    }
    st.push(u);
}

void dfs(int u, vector<vector<int>>& g, vector<int>& seen, int c) {
    seen[u] = c;
    for (int v: g[u]) {
        if (!seen[v]) {
            dfs(v, g, seen, c);
        }
    }
}

bool SCC(vector<vector<int>>& g, vector<vector<int>>& g2) {
    int n = g.size();
    vector<int> seen(n, 0), seen2(n, 0);
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) dfs(i, g, seen);
    }
    int cnt = 0;
    while (st.size()) {
        if (!seen2[st.top()]) dfs(st.top(), g2, seen2, ++cnt);
        st.pop();
    }
    for (int i = 0; i < n; i += 2) 
        if (seen2[i] == seen2[i+1]) return false;
    return true;
}

int main() {
    int test;
    cin >> test;
    for (int tes = 0; tes < test; ++tes) {
        map<string,int> mp;
        vector<vector<int>> g, g2;
        int types;
        cin >> types;
        int cnt = 0;
        cin.get();
        while (types--) {
            string str;
            getline(cin, str);
            string type = "";
            int nums = 0;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == ' ') {
                    mp[type] = cnt;
                    cnt += 2;
                    g.push_back(vector<int>());
                    g.push_back(vector<int>());
                    g2.push_back(vector<int>());
                    g2.push_back(vector<int>());
                    ++nums;
                    type = "";
                }
                else type += str[i];
            }
            if (type != "") {
                mp[type] = cnt;
                cnt += 2;
                g.push_back(vector<int>());
                g.push_back(vector<int>());
                g2.push_back(vector<int>());
                g2.push_back(vector<int>());
                ++nums;
            }
            for (int i = 0; i < nums; ++i) {
                for (int j = 0; j < nums; ++j) {
                    if (i != j) {
                        g[cnt-2*(nums-i)].push_back(cnt-2*(nums-j)+1);
                        g2[cnt-2*(nums-j)+1].push_back(cnt-2*(nums-i));
                    }
                }
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            string s1, s2;
            cin >> s1 >> s1 >> s2;
            int u = mp[s1], v = mp[s2];
            g[u+1].push_back(v);
            g[v+1].push_back(u);
            g2[u].push_back(v+1);
            g2[v].push_back(u+1);
        }
        bool ok = SCC(g, g2);
        cout << "Case #" << tes+1 << ": ";
        if (ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}