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

vector<double> values;
vv64 g;

void dfs(ll u, ll h, ll prev, double chance) {   
    if (g[u].size() == 1 && g[u][0] == prev) {
        values.push_back((double) h * chance);
        return;
    }

    ll ops = g[u].size();
    if (prev != -1) {
        ops--;
    }

    for (auto v : g[u]) {
        if (v == prev) continue;
        dfs(v, h+1, u, chance / ops);
    }
}

int main(){
    F_;
    ll n; cin >> n;
    g.resize(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0, -1, 1);
    double ans = 0;
    forn(i, 0, values.size()) {
        ans += values[i];
    }
    cout << setprecision(8) << ans << ln;

    P_; return 0;
}