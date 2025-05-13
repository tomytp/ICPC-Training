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

void op(set<pair<ll,ll>> &v, ll k){
    set<pair<ll,ll>> aux;

    forn(i, 0, k){
        if(i%2 == 1) aux.insert({(k/2)-(i-1)/2 - 1, (v.begin())->second});
        v.erase(v.begin());
    }

    for(auto x : aux) v.insert(x);
}

void solve(){
    ll n, q; cin >> n >> q;
    set<pair<ll,ll>> v;

    forn(i, 0, n){
        ll a; cin >> a;
        v.insert({i,a});
    }

    forn(i, 0, q){
        ll k; cin >> k;
        op(v, k);
    }

    for(auto x : v){
        cout << x.second << " ";
    }

    cout << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}