#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

ld read(){
    string s; cin >> s;
    ll pow = 1, a = 0;
    for(auto it = s.rbegin(); it!= s.rend(); it++){
        char c = *it;
        if(c == '.') continue;
        a += pow*(c-'0');
        pow*= 10;
    }

    return (ld) a / (pow/10);
}

vector<bool> visited;

void dfs(ll v, vector<v64>& g, vector<ll> &out) {
    visited[v] = true;
    for(auto u : g[v]) if(!visited[u]) dfs(u, g, out);
    out.push_back(v);
}

ld scc(vector<v64>& g, vector<ld>& p) {
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
    vector<ld> cond_p(curr_comp, 1);
    forn(u, 0, n) cond_p[roots[u]] *= p[u];
    
    forn(u, 0, n) {
        for (auto v : g[u]) {
            if (roots[u] != roots[v] && !edges.count({roots[u], roots[v]})) {
                cond_g[roots[u]].push_back(roots[v]);
                edges.emplace(roots[u], roots[v]);
            }
        }
    }

    ld ans = 0;
    forn(i, 0, curr_comp) {
        if (cond_g[i].empty()) ans = max(ans, cond_p[i]);
    }
    return ans;
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<ld> p(n);
    forn(i, 0, n) {
        p[i] = 1 - read();
    }

    vector<v64> g(n);

    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }

    // forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    cout << setprecision(200) << scc(g, p) << ln;

    return 0;
}