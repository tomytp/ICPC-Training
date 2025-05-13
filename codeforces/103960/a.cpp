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
    ll n; cin >> n;
    string s; cin >> s;
    
    ll ans = 0;
    ll curr = 0;

    forn(i, 0, s.size()) {
        if (s[i] == 'a') curr++;
        else {
            if (curr >= 2) ans += curr;
            curr = 0;
        }
    }
    if (curr >= 2) ans += curr;
    curr = 0;

    cout << ans << ln;
    
    return 0;
}