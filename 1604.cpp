#include <bits/stdc++.h>
using namespace std;
const int K = 100010;
int k;
int mx, mx_val;
int amount[K];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k;
    for(int i = 1; i <= k; ++i) {
        cin >> amount[i];
        if (amount[i] > mx) {
            mx = amount[i];
            mx_val = i;
        }
    }
    vector<int> buckets[mx];
    for(int i = 0; i < mx; ++i) 
        buckets[i].emplace_back(mx_val);
    int ptr = 0;
    for(int i = 1; i <= k; ++i) if (i != mx_val) 
        for(int j = 0; j < amount[i]; ++j) {
            buckets[ptr].emplace_back(i);
            ptr = (ptr + 1) % mx;
        }
    for(int i = 0; i < mx; ++i)
        for(auto x: buckets[i]) cout << x << ' ';
}
