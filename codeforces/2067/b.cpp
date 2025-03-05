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

void solve() {
    ll n; cin >> n;
    map<ll,ll> a;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        a[aux]++;
    }
    
    while(a.size()) {        
        debug(a.size());
        debug(a.begin()->first);
        debug(a.begin()->second);
        auto pa = *a.begin();
        
        if (pa.second == 0) {
            a.erase(a.begin());
            continue;
        }

        if (pa.second == 1) {
            cout << "No\n";
            return;
        }

        ll up = pa.second - 2;
        a[pa.first + 1] += up;
        a.erase(a.begin());
    }
    cout << "Yes\n";
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}