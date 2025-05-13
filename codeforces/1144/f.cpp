#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ 42
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) 42
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> visited;
vector<v64> g;
map<p64, bool> mp;

void dfs(ll u, bool is_receiver) {
    visited[u] = is_receiver;

    for (auto& v: g[u]) {
        if (visited[v] != -1) {
            if (visited[v] == is_receiver) {
                cout << "NO" << ln;
                exit(0);
            }
            mp[{u, v}] = is_receiver;
            mp[{v, u}] = !is_receiver;
            continue;
        }
        mp[{u, v}] = is_receiver;
        mp[{v, u}] = !is_receiver;
        dfs(v, !is_receiver);
    }
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    g.resize(n);
    visited.resize(n, -1);
    vector<p64> edges;
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        edges.emplace_back(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, true);
    cout << "YES" << ln;

    forn(i, 0, m) {
        cout << mp[edges[i]];
    }
    cout << ln;
    
    return 0;
}