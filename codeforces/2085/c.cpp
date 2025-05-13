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
    ll x, y; cin >> x >> y;
    if ((x & y) == 0) {
        cout << 0 << ln;
        return;
    }
    if (x == y) {
        cout << -1 << ln;
        return;
    }
    
    ll maior = std::max(x, y);
    ll np = 1;
    while (np <= maior) np <<= 1;
    
    cout  << np - maior << ln;
}
int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}