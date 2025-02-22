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
ll n; v64 vec;


ll get_min(ll l, ll r) {
    ll m = INF;
    forn(i, l, r) {
        m = min(m, vec[i]);
    }
    return m;
}

int main(){
    _;
    cin >> n;
    vec.resize(n);
    map<ll, v64> mp;
    forn(i, 0, n) cin >> vec[i];
    forn(i, 0, n) mp[vec[i]].push_back(i);

    ll ans = 0;
    for (auto& [k, v] : mp) {
        ans++;
        forn(i, 0, v.size() - 1) {
            if (get_min(v[i], v[i+1]) < k) ans++;
        }
    }
    cout << ans << ln;
    return 0;
}