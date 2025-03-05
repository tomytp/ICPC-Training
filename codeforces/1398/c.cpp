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
    v64 v(n+1);
    forn(i, 1, n+1) {
        char aux; cin >> aux;
        v[i] = aux - '0';
    }
    v64 sum(n+1);
    forn(i, 1, n+1) {
        sum[i] = v[i] + sum[i-1];
    }
    map<ll, ll> mp;
    ll ans = 0;
    forn(i, 1, n+1) {
        ll l = sum[i-1] - i + 1;
        mp[l]++;
        ll r = sum[i] - i;
        ans += mp[r];
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}