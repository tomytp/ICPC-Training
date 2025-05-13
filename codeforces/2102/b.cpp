#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
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
        ll n; cin >> n;
        v64 a(n);
        forn(i, 0, n) cin >> a[i];

        ll mag1 = a[0] >= 0 ? a[0] : -a[0];
        ll s = 0, b = 0;

        forn(i, 1, n) {
            ll m = a[i] >= 0 ? a[i] : -a[i];
            if (m < mag1) s++;
            else b++;
        }

        ll k = (n + 1) / 2;
        ll need = k - 1;

        if (need <= b || need >= s) cout << "YES" << ln;
        else cout << "NO" << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
