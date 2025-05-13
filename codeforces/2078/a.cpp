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

int main(){
    _;
    ll t; cin >> t;
    while(t--) {
        ll n, x; cin >> n >> x;
        ll sum = 0;
        forn(i, 0, n) {
            ll aux; cin >> aux;
            sum += aux;
        }
    
        if (sum % n == 0 && sum / n == x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}