#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> st;
void dfs(int u, vector<vector<int>>& g, vector<int>& seen, int c) {
    seen[u] = c;
    for (int v: g[u]) {
        if (!seen[v]) {
            dfs(v, g, seen, c);
        }
    }
    st.push(u);
}

void dfs(int u, vector<vector<int>>& g, vector<int>& seen, int& c, vector<int>& seen2) {
    if (seen2[u] == 1) return;
    seen[u] = 1;
    ++c;
    for (int v: g[u]) {
        if (!seen[v]) {
            dfs(v, g, seen, c, seen2);
        }
    }
}

int SCC(vector<vector<int>>& g, vector<vector<int>>& g2, vector<int>& c) {
    int n = g.size();
    vector<int> seen(n, 0), seen2(n, 0);
    for (int x: c) if (!seen[x]) dfs(x, g2, seen, 1);
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) dfs(i, g, seen, 2);
    }
    int ans = 0;
    while (st.size()) {
        int cnt = 0;
        if (!seen2[st.top()] && seen[st.top()] == 2) {
            dfs(st.top(), g2, seen2, cnt, seen);
            ans += cnt*(cnt-1);
        }
        st.pop();
    }
    return ans;
}

int main() {
    int n, c, tes = 1;
    while (cin >> n >> c) {
        vector<int> amon(c);
        for (int& i: amon) cin >> i;
        vector<vector<int>> g(n, vector<int>()), ng(n, vector<int>());
        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            ng[y].push_back(x);
        }

        int ans = SCC(g, ng, amon);
        cout << "Case #" << tes << ": " << ans << endl;
        ++tes;
    }
}