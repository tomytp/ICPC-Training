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

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    priority_queue<ll> pq;
    v64 visited(n, 0);
    pq.push(0);
    visited[0] = true;
    v64 ans;
    while(ans.size() < n) {
        ll u = -pq.top(); pq.pop();
        ans.push_back(u);
        for (auto v : g[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            pq.push(-v);
        }
    }
    forn(i, 0, n) cout << ans[i] + 1 << " \n"[i==n-1];

    return 0;
}