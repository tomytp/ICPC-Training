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
    ll n, x, y; cin >> n >> x >> y;
    if ((x != 0 && y != 0) || x + y == 0) {
        cout << -1 << ln;
        return;
    }

    x = max(x, y);
    if ((n-1) % x != 0) {
        cout << -1 << ln;
        return;
    }
    ll curr = 0;
    forn(i, 0, n-1) {
        if (i % x == 0) curr = i + 2;
        cout << curr << " \n"[i==n-2];
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}