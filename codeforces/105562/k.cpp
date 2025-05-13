#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-9;
vector<vector<pair<ll,ll>>> adj; // (v, w)

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

// d = distance | p = path
void dijkstra(ll s, v64 &d, v64& p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<p64, vector<pair<ll,ll>>, greater<p64>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d_u = pq.top().first;
        pq.pop();

        if (d_u != d[u]) continue;

        for (auto edge : adj[u]) {
            ll v = edge.first;
            ll w_v = edge.second;

            if (d[u] + w_v < d[v]) {
                d[v] = d[u] + w_v;
                p[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}

ld calc_ve(priority_queue<pair<ll, ld>, vector<pair<ll,ld>>, greater<pair<ll,ld>>> &pq){
    if(pq.empty()) return 0;
    auto [d, p] = pq.top();
    pq.pop();
    return p*d + (1-p)*calc_ve(pq);
}

int main(){
    _; ll n, m, k; cin >> n >> m >> k;
    adj.resize(n);
    forn(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    v64 d0, dn, p0, pn;
    dijkstra(0, d0, p0);
    dijkstra(n-1, dn, pn);

    bool is_possible = false;
    priority_queue<pair<ll, ld>, vector<pair<ll,ld>>, greater<pair<ll,ld>>> pq;
    forn(i, 0, k){
        ll d; cin >> d;
        ld p; cin >> p;
        ll dist = d0[d-1] + dn[d-1];
        pq.push({dist, p});
        if(eq(p, (ld)1)) is_possible = true;
    }

    if(!is_possible){
        cout << "impossible" << ln;
        return 0;
    }

    cout << setprecision(20) << fixed << calc_ve(pq) << ln;

    return 0;
}