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

ll n, q;
vector<vp64> g;
map<ll, v64> folhas_por_capital;
map<p64, ll> ans;
vp64 queries;

v64 winner, times, win_count;

void responde_queries(ll u) {
    if (folhas_por_capital.find(u) == folhas_por_capital.end()) return;
    for (auto start : folhas_por_capital[u]) {
        ans[{u, start}] = win_count[start];
    }
}

p64 recalc(ll u, ll parent) {
    //checar folha NAO PRECISA
    ll t = 1000000000000;
    ll w = u;
    for (auto [v, cost] : g[u]) {
        if (v == parent) continue;

        if (times[v] + cost < t) {
            t = times[v] + cost;
            w = winner[v];
        } else if (times[v] + cost == t && v < w) {
            t = times[v] + cost;
            w = winner[v];
        }
    }
    if (w == u) t = 0;
    return {w, t};
}

void dfs(ll u, ll parent, ll cost_pu) {
    p64 old_parent = {winner[parent], times[parent]};
    p64 new_parent = old_parent;
    p64 old_u = {winner[u], times[u]};
    p64 new_u = old_u;

    if (u != 0) {
        ll wp = winner[parent];
        ll wu = winner[u];
        if (wu == wp) {
            new_parent = recalc(parent, u);
        } else if ((p64){times[parent] + cost_pu, wp} < (p64){times[u], wu}){
            new_u = {wp, times[parent] + cost_pu};
        }
    }

    if (new_parent != old_parent) {
        win_count[new_parent.first]++;
        win_count[old_parent.first]--;
        winner[parent] = new_parent.first;
        times[parent] = new_parent.second;
    }
    if (new_u != old_u) {
        win_count[new_u.first]++;
        win_count[old_u.first]--;
        winner[u] = new_u.first;
        times[u] = new_u.second;
    }

    // cout << u << ln;
    // forn(i, 0, n) cout << win_count[i] << " \n"[i==n-1];
    // forn(i, 0, n) cout << winner[i] << " \n"[i==n-1];
    // forn(i, 0, n) cout << times[i] << " \n"[i==n-1];
    // cout << "----------------------" << ln;
    responde_queries(u);

    for (auto [v, cost] : g[u]) {
        if (v == parent) continue;
        dfs(v, u, cost);
    }

    if (new_parent != old_parent) {
        win_count[new_parent.first]--;
        win_count[old_parent.first]++;
        winner[parent] = old_parent.first;
        times[parent] = old_parent.second;
    }
    if (new_u != old_u) {
        win_count[old_u.first]++;
        win_count[new_u.first]--;
        winner[u] = old_u.first;
        times[u] = old_u.second;
    }

}

void dfs_prep(ll u, ll parent) {
    ll w = u, t = 100000000000;
    if (g[u].size() == 1) {
        t = 0;
    }
    for (auto [v, cost] : g[u]) {
        if (v == parent) continue;
        dfs_prep(v, u);
        if (times[v] + cost < t) {
            t = times[v] + cost;
            w = winner[v];
        } else if (times[v] + cost == t && v < w) {
            t = times[v] + cost;
            w = winner[v];
        }
    }
    if (w == u) t = 0;
    winner[u] = w;
    win_count[w]++;
    times[u] = t;
}

int main(){
    F_;
    cin >> n;
    g.resize(n, vp64());
    winner.resize(n);
    win_count.resize(n);
    times.resize(n);
    forn(i, 0, (n-1)) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    cin >> q;
    queries.resize(q);
    forn(i, 0, q) {
        ll folha, capital; cin >> folha >> capital;
        folha--; capital--;
        queries[i] = {capital, folha};
        folhas_por_capital[capital].push_back(folha);
    }
    dfs_prep(0, -1);
    dfs(0, -1, -1);
    forn(i, 0, q) {
        cout << ans[queries[i]] << ln;
    }
    return 0;
}