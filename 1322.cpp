#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 'z' - 'A' + 1;
int n;
string first, last;
queue<int> position[M];
int nxt[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> last;
    first = last;
    sort(first.begin(), first.end());
    memset(nxt, -1, sizeof nxt);
    for(int i = 0; i < last.size(); ++i) {
        position[last[i]-'A'].push(i);
    }
    for(int i = 0; i < first.size(); ++i) {
        nxt[i] = position[first[i]-'A'].front();
        position[first[i]-'A'].pop();
    }
    for(int cur = n - 1, i = 0; i < first.size(); ++i) {
        cout << first[cur];
        cur = nxt[cur];
    }
}

