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
    ll n, m; cin >> n >> m;
    v64 v(m), suf(m + 1);
    forn(i, 0, m) cin >> v[i], v[i] = min(v[i], n-1);
    sort(v.begin(), v.end());
    for(ll i = m-1; i >= 0; i--) {
        suf[i] = suf[i+1] + v[i];
    }

    ll ans = 0;
    forn(i, 0, m) {
        ll needed = n - v[i];
        auto it = lower_bound(v.begin(), v.end(), needed);
        if (it == v.end()) continue;
        ll idx = it - v.begin();
        ll count = m - idx;
        ll offset = 0;

        if (i >= idx) {
            offset = (v[i]*2) - n + 1;
        }

        ans += ((v[i] * count + suf[idx]) - n * count) + count - offset;
    }
    cout << ans << ln;
    
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}