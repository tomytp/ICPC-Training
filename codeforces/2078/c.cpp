#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n; cin >> n;
    ll n2 = n*2;
    v64 v(n2);
    forn(i, 0, n2) cin >> v[i];
    sort(v.rbegin(), v.rend());

    ll sum = 0;
    forn(i, 1, n+1) {
        sum -= v[i];
    }
    forn(i, n+1, n2) {
        sum += v[i];
    }

    ll ans = (sum - v[0])*-1;

    cout << v[0] << " " << ans << " " << v[1] << " ";
    forn(i, 1, n) {
        cout << v[i+n] << " " << v[i+1] << " ";
    } cout << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}