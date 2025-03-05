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
    string s; cin >> s;
    map<char, ll> mp;
    for(auto c : s) {
        mp[c]++;
    }
    ll alto = mp['-'];
    ll baixo = mp['_'];
    ll ans = baixo;
    if (alto & 1) {
        ans *= alto / 2;
        ans *= 1 + (alto / 2);
    } else {
        ans *= alto / 2;
        ans *= alto / 2;
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}