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

v64 scc(vector<v64>& g) {
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

    return roots;          
}


int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    auto g2 = scc(g);
    cout << *max_element(g2.begin(), g2.end()) + 1 << ln;
    forn(i, 0, g2.size()) cout << g2[i] + 1<< " \n"[i==g2.size() - 1];
    return 0;
}