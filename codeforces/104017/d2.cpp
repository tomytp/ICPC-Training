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

const double ep = 0.0001;

int main(){
    _;
    ll n, m; cin >> n >> m;
    v64 huts(n);
    v64 shops(m);

    forn(i,0,n) cin >> huts[i];
    forn(i,0,m) cin >> shops[i];

    v64 min_dist(n, INF);

    forn(i,0,n){
        forn(j,0,m){
            min_dist[i] = min(min_dist[i], abs(100*i-shops[j]));
        }
    }

    ll best = -INF;

    for(double x = 0; x < 101*n; x += 0.5){
        ll curr = 0;
        forn(i,0,n){
            if(min_dist[i] - ep > abs(100*i-x)){
                curr += huts[i];
            }
        }
        best = max(best, curr);
    }

    cout << best << ln;
    return 0;
}