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

void solve() {
    ll n; cin >> n;
    v64 v(n), pos(n, 0), neg(n, 0);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n) {
        pos[i] = (i==0 ? 0 : pos[i-1]) + (v[i] > 0? v[i] : 0);
    }
    for(ll i = n-1; i >= 0; i--) {
        neg[i] = (i==n-1? 0 : neg[i+1]) + (v[i] < 0? -v[i] : 0);
    }

    ll ans = max(pos[n-1], neg[0]);
    forn(i, 1, n) {
        ans = max(ans, pos[i-1] + neg[i]);
    }

    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}