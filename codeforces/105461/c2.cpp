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

void op(v64 &v, ll k){

    for(ll i = k-2; i >= 0; i -=2){
        assert(i < v.size());
        v.erase(v.begin() + i);
    }
    forn(i, 0, (k+2)/4){
        swap(v[i], v[k/2-i-1]);
    }
}

void solve(){
    ll n, q; cin >> n >> q;
    v64 vec(n);

    forn(i, 0, n){
        cin >> vec[i];
    }

    forn(i, 0, q){
        ll k; cin >> k;
        op(vec, k);
    }

    forn(i,0, vec.size()){
        cout << vec[i] << " ";
    }

    cout << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}