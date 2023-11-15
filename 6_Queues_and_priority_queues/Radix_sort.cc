#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<string, vector<string>, greater<string>> pq;
    string s;
    while (cin >> s) {
        pq.push(s);
    }

    while (!pq.empty()) {
        cout << pq.top();
        pq.pop();
        if (pq.size()) cout << ' ';
    }
    cout << endl;
}