#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq_mi, pq_ma;
    int n;
    while (cin >> n) {
        pq_mi.push(-n);
        pq_ma.push(n);
    }
    while (pq_mi.size()) {
        cout << -pq_mi.top();
        if (pq_mi.size() > 1) cout << ' ';
        pq_mi.pop();
    } 
    cout << endl;
    while (pq_ma.size()) {
        cout << pq_ma.top();
        if (pq_ma.size() > 1) cout << ' ';
        pq_ma.pop();
    } 
    cout << endl;
}