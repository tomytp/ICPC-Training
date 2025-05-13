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
const ll MAXN = 1'000'005;

ll digit_sum(ll n) {
    ll ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
int main(){
    _;
    ll n, k; cin >> n >> k;
    v64 dp(MAXN);
    forn(i, 0, n) {
        ll aux; cin >> aux;
        dp[aux]++;
    }

    ll count = 0;
    for (ll i = MAXN-1; i>= 0; i--) {
        ll to_go = dp[i];
        if (to_go == 0) continue;
        debug(i);
        debug(to_go);
        dp[i] = 0;
        dp[i - digit_sum(i)] += to_go;
        count += to_go;
        if (count >= k) {
            cout << digit_sum(i) << ln;
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}