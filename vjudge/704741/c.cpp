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
    v64 from(n, INF);
    vector<bool> visited(n);
 
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    queue<ll> q;
    q.push(0);    
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
 
        for (auto v : g[u]) {
            if (visited[v]) continue;
            from[v] = u;
            visited[v] = true;
            q.push(v);
        }
    }
 
    if (from[n-1] == INF) {
        cout << "IMPOSSIBLE" << ln;
        return 0;
    }
 
    v64 path = {n-1};
    ll u = n-1;
    while(u != 0) {
        path.push_back(from[u]);
        u = from[u];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << ln;
    forn(i, 0, path.size()) cout << path[i] + 1 << " \n"[i==n-1];
 
    return 0;
}