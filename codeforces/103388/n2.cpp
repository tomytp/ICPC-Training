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
    _;
    ll n, q; cin >> n >> q;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    v64 l(q), r(q), val(q);
    forn(i, 0, q) cin >> l[i] >> val[i] >> r[i], r[i]+= l[i];
    forn(i, 0, q) {
        debug(i);
        debug(l[i]-1); 
        if (val[i] <= v[l[i]-1]) {
            cout << 0 << ln;
            continue;
        }

        ll ans = 0;
        forn(j, l[i], r[i]) {
            if (v[j] >= val[i]) ans++;
        }
        cout << ans << ln;
    }
    

    return 0;
}