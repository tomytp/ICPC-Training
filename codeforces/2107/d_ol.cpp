#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln '\n'

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

struct caminho {
    ll d, u, v;
    v64 path;
    v64 comp;
};

struct node_info {
    ll node;
    v64 dist, par;
};

node_info bfs_far(ll src, vector<v64>& g, vector<char>& alive){
    ll n = g.size() - 1;

    v64 dist(n + 1, -1), par(n + 1, -1);
    ll far = src;
    queue<ll> q;
    dist[src] = 0; q.push(src);

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        if (dist[u] > dist[far] || (dist[u] == dist[far] && u > far))
            far = u;
        for (ll v : g[u])
            if (alive[v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                par[v]  = u;
                q.push(v);
            }
    }
    return {far, move(dist), move(par)};
}

caminho diametro(ll root, vector<v64>& g, vector<char>& valid) {
    v64 comp;
    queue<ll> q; q.push(root);
    vector<char> seen(g.size(), 0);
    seen[root] = 1;

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        comp.push_back(u);
        for (ll v : g[u])
            if (valid[v] && !seen[v]) {
                seen[v] = 1; q.push(v);
            }
    }

    ll any = root;
    auto nd1 = bfs_far(any, g, valid);
    ll A = nd1.node;

    auto nd2 = bfs_far(A, g, valid);
    ll B = nd2.node;

    v64 revPath;
    for (ll x = B; x != -1; x = nd2.par[x]) {
        revPath.push_back(x);
        if (x == A) break;
    }
    reverse(revPath.begin(), revPath.end());

    return {(ll) revPath.size(), max(A, B), min(A, B), move(revPath), move(comp)};
}

void solve() {
    ll n; cin >> n;
    vector<v64> g(n + 1);
    forn(i,0,n-1) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<char> alive(n + 1, 1);

    struct Node {
        ll d, u, v, root;
        bool operator<(Node const& o) const {
            if (d != o.d) return d < o.d;
            if (u != o.u) return u < o.u;
            return v < o.v;
        }
    };
    priority_queue<Node> pq;

    v64 stamp(n + 1, 0);
    ll tick = 1;
    auto push_component = [&](ll r) {
        caminho t = diametro(r, g, alive);
        pq.push({t.d, t.u, t.v, r});
        for (ll x : t.comp) stamp[x] = tick;
    };

    push_component(1);

    v64 ans;
    while (!pq.empty()) {
        Node top = pq.top(); pq.pop();
        if (!alive[top.u] || !alive[top.v]) continue;

        caminho cur = diametro(top.root, g, alive);
        if (cur.d != top.d || cur.u != top.u || cur.v != top.v) {
            pq.push({cur.d, cur.u, cur.v, top.root});
            continue;
        }

        ans.push_back(cur.d);
        ans.push_back(cur.u);
        ans.push_back(cur.v);

        for (ll x : cur.path) alive[x] = 0;

        tick++;
        for (ll x : cur.path)
        for (ll y : g[x]) {
            if (alive[y] && stamp[y] != tick) {
                push_component(y);
                tick++;
            }
        }
            
    }
    forn(i,0, ans.size()) cout << ans[i] << " \n"[i==ans.size()-1];
}

int main() {
    _;
    ll t; cin >> t;

    while (t--) solve();
    return 0;
}