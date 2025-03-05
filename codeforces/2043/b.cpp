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

ll reduce(ll soma) {
    if (soma < 10) return soma;
    ll nsoma = 0;
    while (soma > 0) {
        nsoma += soma % 10;
        soma /= 10;
    }
    
    return reduce(nsoma);
}

void solve() {
    ll n, d; cin >> n >> d;
    ll pq = reduce(d * n);
    cout << 1 << " ";

    if (pq % 3 == 0) cout << 3 << " "; 
    if (d == 5) cout << 5 << " ";

    if (pq == 9) cout << 9 << " ";
    cout << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}