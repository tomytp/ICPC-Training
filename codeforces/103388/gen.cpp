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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _;
    ll y = uniform(1, 20);
    ll n = uniform(1, 20);
    cout << y << " " << n << ln;
    forn(i, 0, y) {
        cout << uniform(0, 10) << " \n"[i==y-1];
    }
    forn(i, 0, n) {
        ll l = uniform(1, y);
        ll r = uniform(l, y) - l;
        ll val = uniform(1, 10);
        cout << l << " " << val << " " << r << ln;
    }

    return 0;
}