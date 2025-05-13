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
    ll n, k, x; cin >> n >> k >> x;
    v64 a(n), pref(n);
    forn(i, 0, n) cin >> a[i];
    pref[0] = a[0];
    forn(i, 1, n) pref[i] = pref[i-1] + a[i];
    
    ll ans = 0;
    forn(i, 0, n) {
        ll to_end = pref[n-1];
        if (i) to_end -= pref[i-1];
        ll temp_tot = max(0ll, x - to_end);
        ll needed_loops = 0;
        if (temp_tot) needed_loops = (temp_tot + pref[n-1] - 1) / pref[n-1];
        if (k > needed_loops) ans += k - needed_loops;
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}