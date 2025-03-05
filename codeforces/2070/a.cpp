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
    ll ans = (n / 15) * 3;
    n %= 15;
    if (n >= 2) {
        ans += 3;
    } else {
        ans += n+1;
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}