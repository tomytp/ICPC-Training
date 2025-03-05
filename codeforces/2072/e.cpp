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
const ll MAXN = 500;
v64 dp(MAXN);

void precalc() {
    forn(i, 2, MAXN) {
        dp[i] = (i * (i-1)) / 2;
    }
}

void solve() {
    ll k; cin >> k;
    ll current_usage = 0;
    v64 blocks;
    for (ll i = MAXN-1; i >= 2; i--) {
        while (dp[i] <= k && current_usage + i <= MAXN) {
            current_usage += i;
            k -= dp[i];
            blocks.push_back(i);
        }
    }

    cout << current_usage << ln;
    ll curr_x = 0;
    forn(i, 0, blocks.size()) {
        forn(j, 0, blocks[i]) {
            cout << curr_x++ << " " << i << ln;
        }
    }
}

int main(){
    _;
    precalc();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}