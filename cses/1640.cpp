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

#include <bits/extc++.h> 

// for ll
struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

__gnu_pbds::gp_hash_table<ll, ll, chash> mp({},{},{},{},{1<<16});


int main(){
    _;
    ll n, x; cin >> n >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    forn(i, 0, n) {
        ll comp = x - v[i];
        auto it = mp.find(comp);
        if (it != mp.end()) {
            cout << it->second + 1  << " " << i+ 1 << ln;
            return 0;
        }        
        mp[v[i]] = i;
    }

    cout << "IMPOSSIBLE" << ln;
    return 0;
}