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
    string a, b; cin >> a >> b;
    vector<bool> to_flip(n); ll tot = 0;
    v64 idx;
    forn(i, 0, n) {
        to_flip[i] = a[i] != b[i];
        tot += to_flip[i];
        if (to_flip[i]) {
            idx.push_back(i);
        }
    }

    if (tot & 1) {
        cout << -1 << ln;
        return;
    }

    if (tot == 0 ) {
        cout << 0 << ln;
        return;
    }

    if (x >= y) {
        if (tot == 2 && abs(idx[0] - idx[1]) == 1) {
            cout << min(x, 2*y) << ln;
            return;
        }
        cout << (tot / 2) * y << ln;
    } 
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}