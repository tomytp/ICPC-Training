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

int main(){
    _; ll a, b; cin >> a >> b;
    ll n = 63 - __builtin_clzll(b);
    
    ll pot = (1ll << n);
    ll resp = 0;
    
    while(((a & pot) == (b & pot)) && (pot > 0)){
        resp += (a & pot);
        pot = pot/2;
    }
    
    while((a & pot) == 0 && pot > 0) pot = pot/2;

    if(pot == 0){
        cout << a << ln;
        return 0;
    }

    if(resp + pot == a){
        cout << a << ln;
        return 0;
    }

    cout << resp + 2*pot << ln;
    
    return 0;
}