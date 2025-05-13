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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    if (n == 1) {
        cout << 0 << ln;
        return;
    }
    vector<p64> ans;
    ans.emplace_back(1, n);
    if ((v[0] + v[n-1]) & 1) {
        v[n-1] = v[0];
    } else {
        v[0] = v[n-1];
    }
    forn(i, 1, n-1) {
        if ((v[i] + v[0]) & 1) {
            v[i] = v[0];
            ans.emplace_back(1, i+1);
        } else {
            v[i] = v[n-1];
            ans.emplace_back(n, i+1);
        }
    }

    cout << ans.size() << ln;
    for (auto& [k, x] : ans) {
        cout << min(k, x) << " " << max(k, x) << ln;
    }

}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}