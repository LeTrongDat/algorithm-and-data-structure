#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 50010;

vector<pair<int, int>> adj[N];
int cost[20], n;
int dp[N], prv[N];
map<long long, int> pos;
long long tele[N];
long long px[11];
int cal_cost(long long &s, long long &t) {
    for(int i = 1; i <= 10; ++i) 
        if (s / px[i] == t / px[i]) 
            return cost[10 - i];
}
long long swap(long long &s, int i, int j) {
    if (i < j) swap(i, j);
    long long beforeI = s / px[i];
    long long i_val = s / px[i-1] % 10;
    long long betweenIandJ = s / px[j] % px[i-j-1];
    long long j_val = s / px[j-1] % 10;
    long long afterJ = s % px[j-1];

    return beforeI * px[i] + j_val * px[i-1] + betweenIandJ * px[j] + i_val * px[j-1] + afterJ;
}
void add_edges(int id) {
    long long s = tele[id];
    for(int i = 1; i <= 10; ++i)
        for(int dig = 0; dig < 10; ++dig) {
            long long t = s - s % px[i] + dig * px[i-1] + s % px[i-1];
            if (pos.count(t)) {
                int v = pos[t];
                if (v != id) adj[id].emplace_back(v, cal_cost(tele[id], tele[v]));
            }
        }
    
    for(int i = 1; i <= 10; ++i) 
        for(int j = i + 1; j <= 10; ++j) {
            long long t = swap(s, i, j);
            if (pos.count(t)) {
                int v = pos[t];
                if (v != id) adj[id].emplace_back(v, cal_cost(tele[id], tele[v]));
            }
        }
}
void dijkstra() {
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    typedef pair<int, int> pi;
    priority_queue< pi, vector< pi >, greater< pi > > pq;

    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto s = pq.top();
        pq.pop();
        int u = s.second;
        int du = s.first;
        for(auto nxt: adj[u]){
            int v = nxt.first;
            int cost = nxt.second;
            if (dp[v] > du + cost) {
                dp[v] = du + cost;
                pq.emplace(dp[v], v);
                prv[v] = u;
            }
        }
    }
}
void trace() {
    vector<int> path;
    int cur = n - 1;
    do {
        path.emplace_back(cur);
        cur = prv[cur];
    } while (cur != 0);
    path.emplace_back(0);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';
    for(auto x: path) cout << x + 1 << ' ';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < 10; ++i) 
        cin >> cost[i];
    for(int i = 0; i < n; ++i) {
        cin >> tele[i];
        pos[tele[i]] = i;
    }
    px[0] = 1;
    for(int i = 1; i < 11; ++i) 
        px[i] = px[i-1] * 10;
    for(int i = 0; i < n; ++i) 
        add_edges(i);
    dijkstra();
    int ans = dp[n-1] == INF ? -1 : dp[n-1];
    cout << ans << '\n';
    if (ans != -1) trace();
}
