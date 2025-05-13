#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll f_sq(ll x) {
    if (x <= 1) return x;
    
    ll l = 1, r = x, ans = 0;
    while (l <= r) {
        ll mid = (r + l) / 2;
        if (mid <= x / mid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve(){
    ll n, m; cin >> n >> m;
    v64 a(n);
    v64 b(n);
    map<ll, ll> h;
    
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> b[i];

    forn(j,0,n){
        ll x = a[j];
        ll r = b[j];
        for(ll i = x-r; i <= x+r; i++){
            ll l = abs(x-i);
            h[i] = max(h[i], f_sq(r*r-l*l));
        }
    }

    ll resp = 0;
    for(auto p: h){
        resp += 2*p.second+1;
    }
    cout << resp << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}