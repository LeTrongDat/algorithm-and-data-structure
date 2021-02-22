#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int ans;
int m, n, k;
vector<int> row[N], col[N];
map<pair<int, int>, bool> blocked;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i) {
        row[i].emplace_back(0);
        row[i].emplace_back(n+1);
        blocked[{i, 0}] = true;
        blocked[{i, n+1}] = true;
    }
    for(int i = 1; i <= n; ++i) {
        col[i].emplace_back(0);
        col[i].emplace_back(m+1);
        blocked[{0, i}] = true;
        blocked[{m+1, i}] = true;
    }
    for(int i = 1; i <= k; ++i) {
        int u, v; 
        cin >> u >> v;
        row[u].emplace_back(v);
        col[v].emplace_back(u);
        blocked[{u, v}] = true;
    }
    for(int i = 1; i <= m; ++i) {
        sort(row[i].begin(), row[i].end());
        for(int j = 0; j < (int) row[i].size() - 1; ++j) {
            int amount = row[i][j+1] - row[i][j] - 1;
            ans += (amount > 1);
        }
    }
    for(int i = 1; i <= n; ++i) {
        sort(col[i].begin(), col[i].end());
        for(int j = 0; j < (int) col[i].size() - 1; ++j) {
            int amount = col[i][j+1] - col[i][j] - 1;
            switch(amount) {
                case 0:
                    break;
                case 1:
                    ans += (blocked.count({col[i][j+1]-1, i-1}) and blocked.count({col[i][j+1]-1, i+1}));
                    break;
                default:
                    ans ++;
            }
        }
    }
    cout << ans;
}
