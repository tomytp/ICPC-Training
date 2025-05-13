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

int main(){
    _;
    ll n; cin >> n;
    v64 v(n);
    ll sum = 0;
    forn(i, 0, n) cin >> v[i], sum += v[i];
    sort(v.rbegin(), v.rend());

    ll half = sum / 2 + 1;
    v64 dp(half+1, 0);
    dp[0] = 1;
    ll ans = 0;
    forn(i, 0, n) {
        for (ll j = half; j >= 0; j--) {
            if (dp[j]) {
                if (j + v[i] >= half) ans += dp[j], debug(v[i]), debug(j);
                else dp[j + v[i]] += dp[j];
            }
        }        
    }

    cout << ans << ln;

    return 0;
}