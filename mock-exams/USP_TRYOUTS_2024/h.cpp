#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef pair<p64, p64> pp64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

#define MAXN 200009
vector<pp64> adj[MAXN];
ll dist[MAXN];

int main() {
    fast_cin();
    ll n, m, t; cin >> n >> m >> t;

    forn(i, 1, m+1) {
        ll a, b, x ,y;
        cin >> a >> b >> x >> y;
        adj[a].pb(mp(mp(b, 0), mp(x, y)));
        adj[b].pb(mp(mp(a, 0), mp(x, y)));
    }

    forn(i, 0, n+1) {
        dist[i] = 2e17;
    }

    priority_queue<p64> pq;
    pq.push(mp(-t, 1));
    dist[1] = t;

    while(!pq.empty()) {
        ll u = pq.top().se;
        ll d = -pq.top().fi;
        pq.pop();
        if (d > dist[u]) continue;
        forn(i, 0, adj[u].size()) {
            pp64 v = adj[u][i];
            ll aceso = v.se.fi;
            ll apagado = v.se.se;
            ll mod = aceso+apagado;
            ll w = mod - dist[u]%mod;
            if(dist[u]%mod < aceso){
                w = 0;
            }
            if (dist[u] + w < dist[v.fi.fi]) {
                dist[v.fi.fi] = dist[u] + w;  
                pq.push(mp(-dist[v.fi.fi], v.fi.fi));
            }
        }
    }

    cout << dist[n] << ln;    

}