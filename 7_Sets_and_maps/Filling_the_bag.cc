#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    int val;
    long long ans = 0;
    multiset<int> bag, left;
    while (cin >> x >> val) {
        if (x == "leave") {
            if (bag.size() < n) {
                bag.insert(val);
                ans += val;
            }
            else if(val > *bag.begin()) {
                left.insert(*bag.begin());
                ans -= *bag.begin();
                bag.erase(bag.begin());
                bag.insert(val);
                ans += val;
            }
            else left.insert(val);
        }
        else {
            if (left.find(val) != left.end()) {
                auto it = left.find(val);
                left.erase(it);
            }
            else {
                auto it = bag.find(val);
                ans -= val;
                bag.erase(it);
                if (left.size()) {
                    it = left.end();
                    --it;
                    bag.insert(*it);
                    ans += *it;
                    left.erase(it);
                }
            }
        }
        cout << ans << endl;
    }
}