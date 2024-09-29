#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;
using vp64 = vector<p64>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define mp make_pair
#define MAXN 1005
#define INF 1'000'000'000'000'000'000

vp64 adjU[MAXN];
ll pairU[MAXN], pairV[MAXN], dist[MAXN];
ll m, n;
ll bound;

bool bfs() {
    queue<ll> q;
    for (ll u = 1; u <= m; u++) {
        if(pairU[u] == 0) {
            dist[u] = 0; q.push(u);
        } else {
            dist[u] = INF;
        }
    }

    dist[0] = INF;
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        if(dist[u] >= dist[0]) continue;
        for (ll i = 0; i < (ll) adjU[u].size(); i++) {
            if(adjU[u][i].second < bound) continue;
            ll v = adjU[u][i].first;
            if(dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + 1;
                q.push(pairV[v]);
            }
        }
    }
    return (dist[0] != INF);
}

bool dfs(ll u) {
    if(u == 0) return true;
    for(ll i = 0; i < (ll) adjU[u].size(); i++) {
        if(adjU[u][i].second < bound) continue;
        ll v = adjU[u][i].first;
        if (dist[pairV[v]] == dist[u]+1) {
            if(dfs(pairV[v])) {
                pairV[v] = u; pairU[u] = v;
                return true;
            }
        }
    }
    dist[u]= INF;
    return false;
}

ll hop() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    ll r = 0;
    while(bfs()) {
        for(ll u = 1; u <=m; u++) {
            if(pairU[u]==0 && dfs(u)) {
                r++;
            }
        }
    }
    return r;
}


int main() {
    FAST_CIN;
    cin >> n >> m;
    ll aux;
    forn(i,1,n+1){
        forn(j,1,m+1){
            cin >> aux;
            adjU[i].push_back(p64(j,aux));
        }
    }
    ll sup = 1'000'000'000;
    ll inf = 1;
    while(sup - inf > 3){
        ll med = (sup+inf)/2;
        bound = med;
        if(hop() == n){
            inf = med;
        } else{
            sup = med;
        }
    }


    for(ll i = sup; i >= inf; i--){
        bound = i;
        if(hop() == n){
            cout << bound << ln;
            forn(j, 1 , n+1) {
                cout << pairU[j] << " ";
            }
            cout << ln;

            return 0;
        }
    }
    return 0; 
}  
