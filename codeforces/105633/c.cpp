#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _; ll n, m, min_cost = 0; cin >> n >> m;

    vector<ll> peso_vert(n);
    vector<vector<pair<ll,ll>>> grafo(n);
    vector<bool> escolhido(n, false);
    vector<ll> path(n, 0);

    forn(i, 0, n) cin >> peso_vert[i];

    forn(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        grafo[a-1].push_back({b-1, c});
        grafo[b-1].push_back({a-1, c});
    }

    escolhido[0] = true;

    priority_queue<pair<ll,pair<ll,ll>>> pq;

    for(auto x : grafo[0]){
        pq.push({-x.second*peso_vert[x.first], x});
    }

    while(!pq.empty()){
        pair<ll,ll> aux = pq.top().second;
        ll curr = aux.first;
        ll dist = aux.second;
        ll curr_cost = pq.top().first;
        pq.pop();

        if(escolhido[curr]) continue;
 
        min_cost += curr_cost;
        debug(curr);
        debug(pq.top().first);
        escolhido[curr]=true;
        path[curr] = dist;
        for(auto x : grafo[curr]){
            if(escolhido[x.first]) continue;
            pq.push({-(dist+x.second)*peso_vert[x.first], {x.first, dist+x.second}});
        }
    }

    cout << -min_cost << ln;
    return 0;
}