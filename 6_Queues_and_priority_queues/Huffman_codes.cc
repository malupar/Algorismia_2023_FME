#include <iostream>
#include <queue>
using namespace std;

typedef long double ld;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    int n;
    priority_queue<ld> pq;
    cin >> n;
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        ld x;
        cin >> x;
        pq.push(-x);
    }

    while (pq.size() > 1) {
        ld u = -pq.top();
        pq.pop();
        ld v = -pq.top();
        pq.pop();
        ans += (u+v)/100;
        pq.push(-(u+v));
    }
    cout << "expected number of bits per letter: " << ans << endl;
}