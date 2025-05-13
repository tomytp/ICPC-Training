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

void dfs(ll u, vector<v64>& g, v64& visited) {
    visited[u] = true;
    for (auto v : g[u]) {
        if (!visited[v]) dfs(v, g, visited);
    }
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    v64 visited(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 roots;
    forn(i, 0, n) {
        if (!visited[i]) {
            dfs(i, g, visited);
            roots.push_back(i + 1);
        }
    }
    
    cout << roots.size() - 1 << ln;
    forn(i, 1, roots.size()) {
        cout << roots[0] << " " << roots[i] << ln; 
    }

    return 0;
}