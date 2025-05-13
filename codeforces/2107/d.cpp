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

struct caminho {
    ll d, u, v;
    v64 path, comp;
};

struct node_info {
    ll node;
    v64 dist, par;
};

node_info bfs_far(ll src, vector<v64>& g, vector<char>& valid)
{
    ll n = g.size() - 1;

    v64 dist(n + 1, -1), par(n + 1, -1);
    queue<ll> q;  dist[src] = 0;  q.push(src);
    ll far = src;

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        if (dist[u] > dist[far] || (dist[u] == dist[far] && u > far))
            far = u;
        for (ll v : g[u])
            if (valid[v] && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                par[v]  = u;
                q.push(v);
            }
    }
    return {far, move(dist), move(par)};
}

caminho diametro(ll root, vector<v64>& g, vector<char>& valid)
{
    v64 comp;
    queue<ll> q; q.push(root);
    vector<char> seen(g.size(), 0);  seen[root] = 1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        comp.push_back(u);
        for (ll v : g[u])
            if (valid[v] && !seen[v]) { seen[v] = 1; q.push(v); }
    }

    ll u = bfs_far(root, g, valid).node;
    auto v_aux = bfs_far(u, g, valid);
    ll v = v_aux.node;

    v64 revPath;
    for (ll x = v; x != -1; x = v_aux.par[x]) {
        revPath.push_back(x);
        if (x == u) break;
    }
    reverse(revPath.begin(), revPath.end());

    return {(ll)revPath.size(), max(u, v), min(u, v), move(revPath), move(comp)};
}

void solve()
{
    ll n; cin >> n;
    vector<v64> g(n + 1);
    forn(i,0,n-1){
        ll u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<char> alive(n + 1, 1);
    v64 mark(n + 1, 0);
    ll tick = 1;

    struct Node {
        ll d, u, v, root;
        bool operator<(Node const& o) const {
            if (d != o.d) return d < o.d;
            if (u != o.u) return u < o.u;
            return v < o.v;
        }
    };
    priority_queue<Node> pq;

    auto push_comp = [&](ll r){
        caminho t = diametro(r, g, alive);
        pq.push({t.d, t.u, t.v, r});
        for (ll x : t.comp) mark[x] = tick;
    };

    push_comp(1); 

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

        ++tick;
        v64 roots;
        for (ll x : cur.path)
            for (ll y : g[x])
                if (alive[y] && mark[y] != tick) {
                    mark[y] = tick;
                    roots.push_back(y);
                }
        for (ll r : roots) push_comp(r);
    }
    forn(i, 0, ans.size()) cout << ans[i] << " \n"[i==ans.size()-1];
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
