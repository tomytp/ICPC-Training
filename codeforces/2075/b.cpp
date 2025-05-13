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

    if (k == 1) {
        if (n == 2) {
            cout << v[0] + v[1] << ln;
            return;
        }
        ll meio = 0;
        forn(i, 1, n-1) {
            meio = max(meio, v[i]);
        }
        v64 temp = {v[0], v[n-1], meio};
        sort(temp.rbegin(), temp.rend());
        cout << temp[0] + temp[1] << ln;
        return;
    }


    sort(v.rbegin(), v.rend());
    ll ans = 0;
    forn(i, 0, k+1) {
        ans += v[i];
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}