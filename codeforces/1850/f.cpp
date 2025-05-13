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
    ll n; cin >> n;
    map<ll, ll> mp;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        mp[aux]++;
    }

    v64 dp(n+1);
    for (auto& [k, count] : mp) {
        ll x = k;
        while(x <= n) {
            dp[x] += count;
            x += k;
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}