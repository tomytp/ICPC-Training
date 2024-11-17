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

vector<int> cats;
vector<bool> visited;
ll rets = 0;

ll n, m; 
vv64 g;

void dfs(ll u, ll curr) {
    if (curr == m) return;
    visited[u] = true;

    if (g[u].size() == 1 && u != 0) {
        rets++;
        return;
    }

    for (auto v : g[u]) {
        if (!visited[v]) {
            dfs(v, cats[v]? curr+1 : 0);
        }
    }

}

int main(){
    F_;
    cin >> n >> m;
    m++;
    cats.resize(n);
    visited.resize(n);
    g.resize(n);
    forn (i, 0, n) cin >> cats[i];
    forn(i, 0, n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, cats[0]);
    cout << rets << ln;
    P_; return 0;
}