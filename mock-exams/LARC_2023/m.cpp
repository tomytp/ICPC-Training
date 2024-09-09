#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln
#define dgb dbg

#define N 100005
#define INF 1000000000000000

v64 adj[N], adjw[N];
ll dist[N];

int main() {
    FAST_CIN;
    ll n, m; cin >> n >> m;
    ll p, g; cin >> p >> g;
    p--; g--;
    forn(i, 0, m) {
        ll u, v, d; cin >> u >> v >> d;
        u--;v--;
        adj[u].push_back(v);
        adjw[u].push_back(d);
        adj[v].push_back(u);
        adjw[v].push_back(d);
    }

    priority_queue<p64> pq;
    pq.push(make_pair(0,p));
    forn(i, 0, n) {
        dist[i] = INF;
    }
    dist[p] = 0;

    while(!pq.empty()) {
        ll u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        forn(i, 0, (ll) adj[u].size()) {
            ll v = adj[u][i];
            ll w = adjw[u][i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    ll distg = dist[g];
    set<ll> legais;
    forn(i, 0, n) {
        if (dist[i] == 2*distg) {
            legais.insert(i);
        }
    }

    adj[g].clear();

    pq.push(make_pair(0,p));
    forn(i, 0, n) {
        dist[i] = INF;
    }
    dist[p] = 0;


    while(!pq.empty()) {
        ll u = pq.top().second;
        ll d = - pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        forn(i, 0, (ll) adj[u].size()) {
            ll v = adj[u][i];
            ll w = adjw[u][i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    set<ll> legais2;
    for(auto x : legais) {
        if (dist[x] != 2*distg) legais2.insert(x);
    }
    if (legais2.size()) {
        for(auto x: legais2) cout << x+1 << " ";
        cout << ln;
    } else {
        cout << "*" << ln;
    }
}