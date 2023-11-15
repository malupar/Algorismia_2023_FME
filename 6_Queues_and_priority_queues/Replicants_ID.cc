#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int m, n;
    while (cin >> m >> n) {
        priority_queue<pair<ll,int>> pq;
        int nums[n], pick[n];

        for(int& i: nums) cin >> i;
        sort(nums, nums+n);

        for (int i = 0; i < n; ++i) {
            pq.push({-nums[i], i});
            pick[i] = 0;
        }
        int last = 1;
        vector<ll> past_res;
        for (int j = 0; j < m; ++j) {
            last = -pq.top().first;
            past_res.push_back(last);
        
            while (last == -pq.top().first) {
                int k = pq.top().second;
                pq.pop();
                if (pick[k] < past_res.size())
                    pq.push({-past_res[pick[k]++]*nums[k], k});
            }
        }

        cout << last << endl;
    }
}
