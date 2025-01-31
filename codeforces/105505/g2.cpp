#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

const ll INF = 1'000'000'000'000;

ll n, q;

vector<vp64> g;
vp64 queries;
map<ll, v64> leafs_by_capital;
map<p64, ll> ans;

v64 best, second, claimed, best_dist, sec_dist;

bool is_new_path_better(ll dist, ll w, ll new_dist, ll new_w) {
    if (new_dist != dist) return new_dist < dist;
    return new_w < w;
}

void prep(ll u, ll parent) {
    if (u != 0 && g[u].size() == 1) {
        best[u] = u;
        best_dist[u] = 0;
        second[u] = g[u].back().first;
        sec_dist[u] = g[u].back().second;
        claimed[u]++;
        return;
    }
    vp64 paths; paths.reserve(g[u].size() - 1);

    for (auto& [v, cost] : g[u]) {
        if (v == parent) continue;
        prep(v, u);
        paths.emplace_back(best_dist[v] + cost, v);
    }
    sort(paths.rbegin(), paths.rend());
    best[u] = paths.back().second;
    best_dist[u] = paths.back().first;
    claimed[paths.back().second]++;
    if (paths.size() > 1) paths.pop_back();

    second[u] = paths.back().second;
    sec_dist[u] = paths.back().first;
}

void answer_queries(ll u) {
    if (leafs_by_capital.find(u) == leafs_by_capital.end()) return;
    for (auto& start : leafs_by_capital[u]) {
        ans[{u, start}] = claimed[start];
    }
}

void change(ll idx, p64 from, p64 to) {
    if (from == to) return;

    claimed[from.first]--;
    claimed[to.first]++;
    best[idx] = to.first;
    best_dist[idx] = to.second;
}

void solve(ll u, ll parent, ll cost_pu) {
    p64 op, np, ou, nu;
    op = {best[parent], best_dist[parent]};
    np = op;
    ou = {best[u], best_dist[u]};
    nu = ou;


    if (u != 0) {
        if (best[parent] == best[u]) {
            np = {second[parent], sec_dist[parent]};
        } else if (is_new_path_better(best_dist[u], best[u], best_dist[parent] + cost_pu, best[parent])) {
            nu = {best[parent], best_dist[parent] + cost_pu};
        }
    }

    change(parent, op, np);
    change(u, ou, nu);

    answer_queries(u);

    for (auto& [v, cost] : g[u]) {
        if (v == parent) continue;
        solve(v, u, cost_pu);
    }

    change(parent, np, op);
    change(u, nu, ou);
}

int main() {
    F_;
    cin >> n;

    g.resize(n);
    best.resize(n);
    second.resize(n);
    claimed.resize(n);
    best_dist.resize(n);
    sec_dist.resize(n);

    forn(i, 0, n-1) {
        ll u, v, c; cin >> u >> v >> c;
        u--; v--;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    cin >> q;
    queries.resize(q);
    forn(i, 0, q) {
        ll leaf, capital; cin >> leaf >> capital;
        leaf--; capital--;
        queries[i] = {capital, leaf};
        leafs_by_capital[capital].push_back(leaf);
    }

    prep(0, -1);
    solve(0, -1, -1);

    forn(i, 0, q) {
        cout << ans[queries[i]] << ln;
    }

    D_; return 0;
}