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

ll sqrtc(ll n){
    return (ll)(ceil(sqrt(n))+1);
}

int solve(){
    ll l,w; cin >> l >> w;

    ll mdc1 = gcd(l-2,w);
    ll mdc2 = gcd(l,w-2);
    ll mdc3 = gcd(l-1,w-1);

    set<ll> resp;
    resp.insert(2);
    
    forn(i,1,sqrtc(mdc1)+2){
        if(mdc1%i == 0){
            resp.insert(i);
            resp.insert(mdc1/i);
        }
    }

    forn(i,1,sqrtc(mdc2)+2){
        if(mdc2%i == 0){
            resp.insert(i);
            resp.insert(mdc2/i);
        }
    }
    
    forn(i,1,sqrtc(mdc3)+2){
        if(mdc3%i == 0){
            resp.insert(i);
            resp.insert(mdc3/i);
        }
    }
    
    cout << resp.size() << " ";
    for(ll x: resp) cout << x << " ";
    cout << ln;
    return 0;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
}