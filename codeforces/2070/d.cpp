#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 998244353;

void dfs_map(ll u, ll parent, ll curr_h, vector<v64>& g, v64& h) {
    h[u] = curr_h;
    for(auto v : g[u]) {
        if (v == parent) continue;

        dfs_map(v, u, curr_h+1, g, h);
    }
}

void solve() {
    ll n; cin >> n;
    vector<v64> g(n);
    v64 h(n), starting(n);
    forn(i, 1, n) {
        ll aux; cin >> aux;
        aux--;
        g[aux].push_back(i);
    }

    dfs_map(0, -1, 0, g, h);

    map<ll, v64> h_map;
    map<ll, ll> h_sum;
    forn(i, 0, n) {
        h_map[h[i]].push_back(i);
    }
    
    while(h_map.size()) {
        auto it = --h_map.end();
        v64 vertices = it->second;
        ll cur_h = it->first;
        h_map.erase(it);
        
        for (auto v : vertices) {
            ll ans = 1;
            ans = (ans + h_sum[cur_h + 1])%MOD;
            for (auto child : g[v]) {
                ans = (MOD + (ans - starting[child])) % MOD;
            }
            h_sum[cur_h] = (h_sum[cur_h] + ans) % MOD;
            starting[v] = ans;
        }
    }

    ll ans = 1;
    for (auto v : g[0]){
        ans = (ans + starting[v])%MOD;
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}