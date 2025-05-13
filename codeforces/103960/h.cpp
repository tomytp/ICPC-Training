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

vector<bool> visited;

void dfs(ll v, vector<v64>& g, vector<ll> &out) {
    visited[v] = true;
    for(auto u : g[v]) if(!visited[u]) dfs(u, g, out);
    out.push_back(v);
}

vector<v64> scc(vector<v64>& g) {
    int n = g.size();
    v64 order, roots(n, 0);

    vector<v64> adj_rev(n);
    forn(u, 0, n) for (ll v : g[u]) adj_rev[v].push_back(u);

    visited.assign(n, false);
    forn(i, 0, n) if (!visited[i]) dfs(i, g, order);
    reverse(order.begin(), order.end());
    
    // second series of depth first searches
    visited.assign(n, false);
    ll curr_comp = 0;
    for (auto v : order) {
        if (!visited[v]) {
            v64 component; dfs(v, adj_rev, component);
            for (auto u : component) roots[u] = curr_comp;
            curr_comp++;
        }
    }

    // add edges to condensation graph
    set<p64> edges;
    vector<v64> cond_g(curr_comp);
    forn(u, 0, n) {
        for (auto v : g[u]) {
            if (roots[u] != roots[v] && !edges.count({roots[u], roots[v]})) {
                cond_g[roots[u]].push_back(roots[v]);
                edges.emplace(roots[u], roots[v]);
            }
        }
    }
    return cond_g;          
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    vector<v64> cond_g = scc(g);

    if (cond_g.size() == 1) {
        cout << 0 << ln;
        return 0;
    }

    v64 chegadas(cond_g.size()), saidas(cond_g.size());
    forn(u, 0, cond_g.size()) {
        saidas[u] = cond_g[u].size();
        for(auto v : cond_g[u]) {
            chegadas[v]++;
        }
    }

    ll sources = 0, tinks = 0;
    forn(i, 0, cond_g.size()) {
        if (!saidas[i]) tinks++;
        if (!chegadas[i]) sources++;
    }

    cout << max(sources, tinks) << ln;
    return 0;
}