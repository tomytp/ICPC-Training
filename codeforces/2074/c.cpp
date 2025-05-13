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

void solve(){
    ll x; cin >> x;
    ll pot2 = 1;
    ll i = 0;
    ll id0 = -1;
    ll id1 = -1;
    while(2*pot2 < x){
        if((id0 == -1) && ((pot2 & x) == 0)){
            id0 = i;
        }
        if((id1 == -1) && ((pot2 & x) != 0)){
            id1 = i;
        }    
        i++;
        pot2 *= 2;
    }

    if((id0 == -1) || (id1 == -1)){
        cout << -1 << ln;
        return;
    }

    ll ans = ((1<<id0) + (1<<id1)); 
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}