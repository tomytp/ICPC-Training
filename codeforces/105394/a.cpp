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

ll dfs(ll u, vector<v64>& g, v64& visited) {
    visited[u] = true;
    ll aux = 1;
    for (auto v : g[u]) {
        if (!visited[v]) {
            aux += dfs(v, g, visited);
        }
    }

    return aux;
}

int main(){
    _;
    ll n, m; cin >> n >> m;

    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    v64 visited(n);
    ll mx = 0;
    forn(i, 0, n) {
        if (!visited[i]) {
            mx = max(mx, dfs(i, g, visited));
        }
    }
    cout << mx << ln;

    return 0;
}