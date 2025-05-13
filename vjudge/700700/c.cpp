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

bool can_do(ll n, ll k, v64& needed, v64& storage, ll count) {
    forn(i, 0, n) {
        ll to_use = needed[i] * count;
        if (to_use <= storage[i]) continue;
        
        if (to_use - storage[i] <= k) {
            k -= to_use - storage[i];
        } else {
            return false;
        }
    }
    return true;
}

ll bs(ll n, ll k, v64& needed, v64& storage) {
    ll l = 0, r = 2'000'000'005;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r-l) / 2;

        if (can_do(n, k, needed, storage, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main(){
    _;
    ll n, k; cin >> n >> k;
    v64 needed(n), storage(n);
    forn(i, 0, n) cin >> needed[i];
    forn(i, 0, n) cin >> storage[i];

    cout << bs(n, k, needed, storage) << ln;
    

    return 0;
}