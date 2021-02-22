#include <bits/stdc++.h>
using namespace std;
const int N = 60010;
long long ans = 0;
int n;
int p[N];
void cal_energy() {
    long long cur = 0;
    for(int i = 1; i <= n; ++i) {
        cur = max(cur + p[i], (long long)p[i]);
        ans = max(ans, cur);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) 
        cin >> p[i];
    cal_energy();
    cout << ans;
}
