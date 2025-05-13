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

int main(){
    _;
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll ans = 0;
    map<ll, ll> mp;
    forn(i, 0, n) {
        if (mp[v[i]] > 0) {
            mp[v[i]]--;
        } else {
            ans++;
        }
        mp[v[i] - 1]++;
    }
    cout << ans << ln;
    return 0;
}