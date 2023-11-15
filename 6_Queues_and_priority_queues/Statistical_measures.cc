#include <iostream>
#include <set>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    multiset<int> st;
    string s;
    double sum = 0;
    while (cin >> s) {
        if (s == "delete") {
            if (st.size()) {
                auto it = st.begin();
                sum -= *it;
                it = st.erase(it);
            }
        }
        else {
            int x;
            cin >> x;
            st.insert(x);
            sum += x;
        }
        if (st.size()) {
            auto it = st.end();
            --it;
            cout << "minimum: " << *st.begin() << ", maximum: " << *it << ", average: " << sum/st.size() << endl;
        }
        else cout << "no elements" << endl;
    }
}