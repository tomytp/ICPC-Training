    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<ll, ll> p64;
    typedef vector<ll> v64;
    typedef vector<int> v32;
    typedef vector<v32> vv32;
    typedef vector<v64> vv64;
    typedef vector<p64> vp64;

    #define D_ false
    #define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define P_ if(D_)cout<<"DEBUG\n"
    #define dbg(x) if(D_) cout << #x << " = " << x << ln

    #define forn(i, s, e) for(ll i = s; i < e; i++)
    #define ln "\n"
    #define dgb dbg

    vector<vp64> g;
    vector<bool> visited;
    ll low, up;
    ll n;

    ll dfs(ll u) {
        visited[u] = true;

        ll tots = 1;
        for (auto p : g[u]) {
            if (visited[p.first]) continue;
            ll sz = dfs(p.first);
            tots += sz;
            if (sz & 1) {
                low += p.second;
            }
            up += p.second * min(sz, n-sz);
        }
        return tots;
    }

    void solve() {
        ll k; cin >> k;
        n = k * 2;
        low = 0; up = 0;
        g.clear();
        g.resize(n, vp64());
        visited.clear();
        visited.resize(n, false);
        forn(i, 0, n-1) {
            ll u, v, w; cin >> u >> v >> w;
            u--; v--;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        dfs(0);
        cout << low << " " << up << ln;
    }

    int main(){
        F_;
        ll t; cin >> t;
        while(t--) solve();
        P_; return 0;
    }