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
map<ll, set<ll>> lmap;

ll solveq(ll q, v64& dp, v64& left) {
    ll n = dp.size();
    ll pos = n - 1;
    ll curr = q;
    ll eaten = 0;
    
    while (pos >= 0) {
        ll bit = 64 - __builtin_clzll(curr);
        
        auto it = lmap[bit].upper_bound(pos);
        

        break;
    }
    
    return eaten;
}
void solve() {
    ll n; cin >> n;
    ll q; cin >> q;

    v64 v(n), dp(n), left(n);
    forn(i, 0, n) cin >> v[i];
    dp[n-1] = v[n-1];
    left[n-1] = 64 - __builtin_clzll(v[n-1]);
    for(ll i = n-2; i >= 0; i--) {
        dp[i] = v[i] ^ dp[i+1];
        left[i] = 64 - __builtin_clzll(v[i]);
        lmap[left[i]].insert(i);
    }
 
    // forn(i, 0, n) cout << dp[i] << " \n"[i==n-1];
    // forn(i, 0, n) cout << left[i] << " \n"[i==n-1];
 
    forn(i, 0, q) {
        ll aux; cin >> aux;
        cout << solveq(aux, dp, left) << " \n"[i==q-1];
    }

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}