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

ll M = 5000;

void solve() {
    ll n; cin >> n;
    v64 v(n+1);
    forn(i, 1, n+1) cin >> v[i];
    vector<vector<p64>> dp(n+1, vector<p64>(M+1, {0,0}));

    forn(i, 0, M+1) {
        dp[0][i].second = -INF;
    }

    forn(i, 1, n+1) {
        forn(j, 1, v[i]) {
            dp[i][j] = dp[i-1][j];
            dp[i][j].first += v[i] - j;
        }

        p64 melhor_maior = {INF, INF};
        forn(j, v[i], M+1) {
            melhor_maior = min(melhor_maior, dp[i-1][j]);
        }
        dp[i][v[i]] = melhor_maior;
        forn(j, v[i] + 1, M+1) {
            ll n_slow = max(-v[i], dp[i-1][j].second);
            dp[i][j].first = dp[i-1][j].first + (v[i] + n_slow);
            dp[i][j].second = n_slow;
        }
    }

    ll ans = INF;
    forn(j, 1, M + 1) {
        ans = min(ans, dp[n][j].first);
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}