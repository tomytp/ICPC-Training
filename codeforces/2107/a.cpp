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
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        v64 v(n);
        ll mx = 0;
        forn(i, 0, n) cin >> v[i], mx = max(mx, v[i]);
    
        bool all_same = true;
        forn(i, 1, n) if (v[i] != v[i-1]) all_same = false;
    
        if (all_same) {
            cout << "no\n";
        } else {
            cout << "yes\n";
            forn(i, 0, n) {
                if (v[i] == mx) cout << 1 << " \n"[i==n-1];
                else  cout << 2 << " \n"[i==n-1];
            }
        }
    
    }

    return 0;
}