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

void solve() {
    ll n, m; cin >> n >> m;
    vector<v64> v(n, v64(m));
    forn(i, 0, n) forn(j, 0, m) cin >> v[i][j];
    set<ll> mp;
    set<ll> cores;
    forn(i, 0, n) {
        forn(j, 0, m) {
            cores.insert(v[i][j]);
            if (j+1 < m && v[i][j] == v[i][j+1]) mp.insert(v[i][j]);
            if (i+1 < n && v[i][j] == v[i+1][j]) mp.insert(v[i][j]);
        }
    }
    ll ans = cores.size() - 1;
    if (mp.size()) {
        ans += mp.size() -1;
    }
    cout << ans << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}