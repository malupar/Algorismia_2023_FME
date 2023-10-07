#include <iostream>
#include <vector>
using namespace std;

vector<int> b,d;
vector<vector<int>> friends;

void print() {
    for (int i = 0; i < friends.size(); ++i) {
        if (i) cout << '-';
        cout << char(friends[i][0]+'A')<<friends[i][1] << char(friends[i][2]+'a');
    }
    cout << endl;
}

void bt(int i, int n) {
    if (i == n) {
        print();
        return;
    }
    vector<int> f;
    f.push_back(i);
    for (int j = 0; j < n; ++j) {
        if (!b[j]) {
            b[j] = 1;
            f.push_back(j);
            for (int k = 0; k < n; ++k) {
                if (!d[k]) {
                    d[k] = 1;
                    f.push_back(k);
                    friends.push_back(f);
                    bt(i+1, n);
                    friends.pop_back();
                    f.pop_back();
                    d[k] = 0;
                }
            }
            b[j] = 0;
            f.pop_back();
        }
    }
}

int main() {
    int n, test = 1;
    while (cin >> n) {
        if (!n) break;
        b = vector<int> (n);
        d = vector<int> (n);
        cout << "Case " << test << endl;
        bt(0, n);
        ++test;
    }
}