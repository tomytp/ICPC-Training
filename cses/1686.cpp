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

vector<v64> scc(vector<v64>& g, v64& price) {
    int n = g.size();
    v64 order, roots(n, 0);

    vector<v64> adj_rev(n);
    forn(u, 0, n) for (ll v : g[u]) adj_rev[v].push_back(u);

    visited.assign(n, false);
    forn(i, 0, n) if (!visited[i]) dfs(i, g, order);
    reverse(order.begin(), order.end());
    
    visited.assign(n, false);
    ll curr_comp = 0;
    for (auto v : order) {
        if (!visited[v]) {
            v64 component; dfs(v, adj_rev, component);
            for (auto u : component) roots[u] = curr_comp;
            curr_comp++;
        }
    }

    set<p64> edges;
    vector<v64> cond_g(curr_comp);
    v64 nprices(curr_comp);
    forn(u, 0, n) {
        nprices[roots[u]] += price[u];
        for (auto v : g[u]) {
            if (roots[u] != roots[v] && !edges.count({roots[u], roots[v]})) {
                cond_g[roots[u]].push_back(roots[v]);
                edges.emplace(roots[u], roots[v]);
            }
        }
    }
    swap(price, nprices);
    return cond_g;          
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    v64 v(n); forn(i, 0, n) cin >> v[i];
    vector<v64> g(n);
    forn(i, 0, m) {
        ll u, k; cin >> u >> k;
        u--; k--;
        g[u].push_back(k);
    }

    auto g2 = scc(g, v);
    
    v64 ans(g2.size());
    ll out = 0;
    for (ll i = g2.size() - 1; i>= 0; i--) {
        for (auto k : g2[i]) ans[i] = max(ans[i], ans[k]);
        ans[i] += v[i];
        out = max(out, ans[i]);
    } 
    cout << out << ln;

    return 0;
}