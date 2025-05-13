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

void solve() {
    ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    map<ll, ll> mp;
    forn(i, 0, k) {
        mp[v[i]]++;
    }
    
    ll ans = k - mp.size();

    forn(i, k, n) {
        mp[v[i-k]]--;
        if (mp[v[i-k]] == 0) {
            mp.erase(v[i-k]);
        }
        mp[v[i]]++;
        
        debug(mp.size());
        ans = min(ans, k - (ll) mp.size());
    }
    cout << ans << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}