#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int l[4*N], r[4*N], s[4*N];

void build(int x, int le, int ri) {
    l[x] = le;
    r[x] = ri;
    s[x] = ri - le + 1;
    if (le == ri) return;
    int mid = (le + ri) >> 1;
    build(2*x, le, mid);
    build(2*x+1, mid+1, ri);
}
void del(int x, int pos) {
    if (l[x] == r[x]) {
        s[x] = 0;
        return;
    }
    int mid = (l[x] + r[x]) >> 1;
    if (l[x] <= pos && pos <= mid) 
        del(2*x, pos);
    else del(2*x+1, pos);
    s[x] --;
}
int find(int x, int amount) {
    if (l[x] == r[x]) return l[x];
    if (s[2*x] >= amount) return find(2*x, amount);
    return find(2*x+1, amount - s[2*x]);
}
int get_sum(int x, int le, int ri) {
    if (le <= l[x] && r[x] <= ri) return s[x];
    if (r[x] < le || ri < l[x]) return 0;
    return get_sum(2*x, le, ri) + get_sum(2*x+1, le, ri);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    build(1, 1, n);
    int cur_pos = k;
    for(int i = 1; i <= n; ++i) {
        cout << cur_pos << ' ';
        del(1, cur_pos);
        if (i == n) break;
        int step = n - i < k ? k % (n - i) ? k % (n - i) : (n - i) : k;
        int fromOneToK = get_sum(1, 1, cur_pos);
        int fromKtoN = get_sum(1, cur_pos, n);
        cur_pos = fromKtoN >= step ? cur_pos = find(1, fromOneToK + step) : find(1, step - fromKtoN);
    }
}
