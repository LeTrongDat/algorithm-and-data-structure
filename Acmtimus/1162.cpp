#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector<tuple<int, double, double>> adj[N];
int n, m, s;
double init;
double dp[N];
double exchange(double init, double ex, double com) {
    return (init - com) * ex;
}
void dfs(int u) {
    for(auto ex_point: adj[u]) {
        int v;
        double ex, com;
        tie(v, ex,com) = ex_point;
        if (dp[v] < exchange(dp[u], ex, com)) {
            dp[v] = exchange(dp[u], ex, com);
            dfs(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s >> init;

    dp[s] = init;

    for(int i = 1; i <= m; ++i) {
        int u, v;
        double ex1, com1;
        double ex2, com2;
        cin >> u >> v >> ex1 >> com1 >> ex2 >> com2;
        adj[u].emplace_back(v, ex1, com1);
        adj[v].emplace_back(u, ex2, com2);
    }
    dfs(s);
    cout << (dp[s] > init ? "YES" : "NO");
}
