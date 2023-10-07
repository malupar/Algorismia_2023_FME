#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    while (cin >> n >> m) {
        int fib[n+4];
        fib[0] = 0;fib[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fib[i] = (fib[i-1]+fib[i-2])%m;
        }
        cout << fib[n] << endl;
    }
}
