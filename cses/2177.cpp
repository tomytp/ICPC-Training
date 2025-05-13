#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<v64> g;
vector<bool> visited;
vector<ll> tin;
vector<ll> lo;
set<p64> span_edges;

ll timer = 0;

void dfs(ll u, ll parent) {
    visited[u] = true;
    tin[u] = timer++;
    lo[u] = tin[u];

    for (auto v : g[u]) {
        if (v == parent) continue;
        if (visited[v]) {
            lo[u] = min(lo[u], tin[v]);
            continue;
        }
        span_edges.emplace(u, v);
        span_edges.emplace(v, u);
        dfs(v, u);
        lo[u] = min(lo[u], lo[v]);
        debug(lo[v]);
        debug(tin[u]);
        debug(u);
        debug(v);
        if (lo[v] > tin[u]) {
            cout << "IMPOSSIBLE" << ln;
            exit(0);
        }
    }
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<p64> edges(m);
    g.resize(n);
    visited.resize(n);
    tin.resize(n);
    lo.resize(n);
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    if (timer != n) {
        cout << "IMPOSSIBLE" << ln;
        return 0;
    }

    for (auto [u, v] : edges) {
        if (span_edges.count({u, v})) {
            if (tin[u] > tin[v]) swap(u, v);
        } else {
            if (tin[v] > tin[u]) swap(u, v);
        }

        cout << u+1 << " " << v+1 << ln;
    }
    return 0;
}