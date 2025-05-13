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

struct pass {
    ll period = 0, num_travel = 0, cost = 0;
};

vector<p64> events;
vector<pass> passes;

ll find_next(ll i, ll j, ll n){
    pass p = passes[j];
    for(ll t = min(passes[j].num_travel-1 + i, n-1); t >= i; --t){
        debug(t);
        if(events[t].first - events[i].first < p.period) return t;
        debug(t);

    }
    return i;
}

ll bs(ll i, ll j, ll n) {
    pass p = passes[j];
    ll l = i, r = min(passes[j].num_travel-1 + i, n-1);
    ll ans = i;

    while(l <= r) {
        ll mid = l + (r-l) / 2;

        if (events[mid].first - events[i].first < p.period) {
            ans = mid;
            l = mid +1;
        } else {
            r = mid -1;
        }
    }
    return ans;
}

int main(){
    _;
    ll n; ll k;
    cin >> n >> k;

    events.resize(n);
    passes.resize(k);

    forn(i,0,n){
        cin >> events[i].first;
        cin >> events[i].second;
    }

    // events.push_back({events[n-1].first+1, 0});

    forn(i,0,k){
        cin >> passes[i].period;
        cin >> passes[i].num_travel;
        cin >> passes[i].cost;
    }

    v64 best_cost(n+1, INF);
    // vector<v64> dp(n+1, v64(k, INF));

    best_cost[n] = 0;
    
    // forn(j,0,k){
    //     dp[n][j] = 0;
    // }

    for(ll i = n-1; i >= 0; i--){
        ll curr_cost = best_cost[i+1] + events[i].second;

        forn(j,0,k){
            ll prox = bs(i, j, n);
            debug(i);
            debug(j);
            debug(prox);
            curr_cost = min(curr_cost, best_cost[prox+1] + passes[j].cost);
        }

        best_cost[i] = curr_cost; 
    }

    // forn(i,0,n) cout << best_cost[i] << " \n"[i==n-1];
    
    cout << best_cost[0] << ln;
    return 0;
}