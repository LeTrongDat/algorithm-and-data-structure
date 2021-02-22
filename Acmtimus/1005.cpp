#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int ans = INT_MAX, n;
int w[N];
void cal_diff(int i, int first, int second) {
    if (i > n) {
        ans = min(ans, abs(first - second));
        return;
    }
    cal_diff(i + 1, first + w[i], second);
    cal_diff(i + 1, first, second + w[i]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> w[i];
    cal_diff(1, 0, 0);
    cout << ans;
    return 0;
}
