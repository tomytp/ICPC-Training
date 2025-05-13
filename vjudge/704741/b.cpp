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

void dfs(ll u, vector<v64>& g, v64& ans) {
    for (auto v : g[u]) {
        dfs(v, g, ans);
        ans[u] += ans[v] + 1;
    }
}

int main(){
    _;
    ll n; cin >> n;
    vector<v64> g(n);
    v64 ans(n, 0);
    
    forn(i, 1, n) {
        ll b; cin >> b; b--;
        g[b].push_back(i);
    }

    dfs(0, g, ans);
    
    forn(i, 0, n) cout << ans[i] << " \n"[i==n-1];

    return 0;
}