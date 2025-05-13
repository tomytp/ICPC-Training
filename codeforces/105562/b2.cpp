#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define pb push_back
 
void dbg_out() { cerr << endl; }
template<typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
 
const int N = 6e5 + 10;
const int INF = 1e9;
 
vector<int> adj[N];
 
void solve() {
    int n, m; cin >> n >> m;
 
    vector<int> a(n);
    vector<pair<int, int>> edges(m);
 
    for (auto &u : a) cin >> u;
    for (auto &[x, y] : edges) cin >> x >> y, x--, y--;
 
    // verifica se eh uma cor so
    {
        int sum = 0;
        for (auto u : a) sum += u;
        if (sum == 0 || sum == n) {
            cout << "1\n";
            return;
        }
    }
 
    for (auto [x, y] : edges) {
        if (a[x] != a[y]) {
            adj[x].pb(y + n);
            adj[y].pb(x + n);
            // dbg(x, y + n);
            // dbg(y, x + n);
        }
        else {
            adj[x + n].pb(y);
            adj[y + n].pb(x);
            // dbg(x + n, y);
            // dbg(y + n, x);
        }
    }
 
    // tem que ver se tem ciclo
    vector<int> order, vis(2 * n);
 
    function<void(int)> dfs = [&] (int x) {
        if (vis[x]) return;
        vis[x]++;
        for (auto u : adj[x]) dfs(u);
        order.pb(x);
    };
 
    for (int i = 0; i < 2 * n; i++) if (!vis[i])
        dfs(i);
 
    assert(order.size() == 2 * n);
 
    vector<int> pos(2 * n);
    for (int i = 0; i < order.size(); i++) pos[order[i]] = i;
 
    for (int i = 0; i < 2 * n; i++)
        for (auto j : adj[i]) if (pos[j] > pos[i]) {
            cout << "infinity\n";
            return;
        }
 
    auto get_color = [&] (int x) {
        return x >= n ? a[x - n] : a[x];
    };
 
  vector<vector<int>> memo(2*n, vector<int>(4));
 
  auto get_id = [&](int u, int v) {
    return get_color(u) + get_color(v)*2;
  };
 
  // 00 -> 01
  // 01 -> 11
  // 10 -> 00
  // 11 -> 10
  auto prev = [&](int x) {
    if (x == 0) return 2;
    if (x == 1) return 0;
    if (x == 2) return 3;
    return 1;
  };
 
    for (auto u : order) {
    for (auto v : adj[u]) {
      memo[u][get_id(u, v)] = 2;
    }
 
        for (auto v : adj[u]) {
      int id = get_id(u, v);
      for (int i = 0; i < 4; i++) if (memo[v][prev(id)]) {
        memo[u][id] = max(memo[u][id], memo[v][prev(id)]+1);
      }
        }
    }
 
  vector<int> best = {1, 1, 1, 1};
  for (int u = 0; u < 2*n; u++) {
    for (int i = 0; i < 4; i++) {
      best[i] = max(best[i], memo[u][i]);
    }
  }
 
  int ans = INF;
  for (int i = 0; i < 4; i++) {
    ans = min(ans, best[i]);
  }
    cout << ans+1 << "\n";

  for(auto x : memo){
    for(auto y : x){
        cout << y << " ";
    }
    cout << "\n";
  }
}   
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}