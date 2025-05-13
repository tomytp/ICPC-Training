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
    string a, b; cin >> a >> b;
    ll ca = 0, cb = 0;
    forn(i, 0, n) {
        if (i&1) {
            ca += a[i] == '1';
            cb += b[i] == '1';
        } else {
            cb += a[i] == '1';
            ca += b[i] == '1';
        }
    }

    if (cb <= n/2 && ca <= (n+1)/2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}