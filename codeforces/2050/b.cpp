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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll odd_sz = 0, even_sz = 0, odd_sum = 0, even_sum = 0;
    forn(i, 0, n) {
        if (i & 1) {
            odd_sz++;
            odd_sum += v[i];
        } else {
            even_sz++;
            even_sum += v[i];
        }
    }

    if (odd_sum % odd_sz == 0 && even_sum % even_sz == 0 && (odd_sum/odd_sz) == (even_sum/even_sz)) {
        cout << "YES" << ln;
    } else {
        cout << "NO" << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}