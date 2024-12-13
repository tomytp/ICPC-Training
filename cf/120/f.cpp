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

p64 dfs(ll u, ll previous, vv64 vec) {
    p64 m = {0, u};
    for (auto v : vec[u]) {
        if (v == previous) continue;

        p64 aux = dfs(v, u, vec);
        if (aux.first >= m.first) {
            m = {aux.first + 1, aux.second};
        }
    }
    return m;
}

int main(){
    F_;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    ll ans = 0;
    forn(i, 0, n) {
        ll k; cin >> k;
        vv64 v(k+1);
        forn(j, 0, k-1) {
            ll a, b; cin >> a >> b;
            a--; b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        p64 p = dfs(0, -1, v);
        p = dfs(p.second, -1, v);
        ans += p.first;
    }
    cout << ans << ln;
    P_; return 0;
}