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

void solve() {
    ll n, k; cin >> n >> k;
    v64 v(n);
    v[n-1] = n-1;
    v[n-2] = n;

    ll rest = k&1 ? n : n-1;
    forn(i, 0, n-2) {
        v[i] = rest;
    }

    forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}