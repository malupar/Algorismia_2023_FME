#include <iostream>
#include <vector>

using namespace std;

void bt (int n, vector<char>& word, vector<bool>& usedv, vector<bool>& usedc,string& v, string& c) {
    if (2*n == word.size()) {
        for (auto x: word) cout << x;
        cout << '\n';
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (word.size()&1) {
                if (!usedv[i]) {
                    usedv[i] = 1;
                    word.push_back (v[i]);
                    bt (n, word, usedv, usedc, v, c);
                    word.pop_back();
                    usedv[i] = 0;
                }
            }
            else {
                if (!usedc[i]) {
                    usedc[i] = 1;
                    word.push_back (c[i]);
                    bt (n, word, usedv, usedc, v, c);
                    word.pop_back();
                    usedc[i] = 0;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    string c, v;
    cin >> c >> v;
    vector<char> word;
    vector<bool> usedv (n,false), usedc (n,false);
    bt (n, word, usedv, usedc, v, c);
}
