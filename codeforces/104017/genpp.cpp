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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

const ll MAX_ANG = 5;
const ll MAX_R = 20;

int main(){
    _;
    cout << 1 << ln;
    ll n = uniform(2, 10);
    ll m = uniform(1, 5);
    cout << n+m << ln;
    forn(i, 0, n) {
        ll aux = uniform(1, MAX_R);
        ll aux2 = uniform(0, MAX_ANG-1);
        ll aux3 = (aux2 + uniform(1, MAX_ANG-1)) % 5;
        cout << "C " << aux << " " << aux2 << " " << aux3 << ln;
    }
    forn(i, 0, m) {
        ll aux = uniform(1, MAX_R);
        ll aux2 = ((aux + uniform(0, MAX_R-2)) % MAX_R) + 1;
        ll aux3 = uniform(0, MAX_ANG-1);
        if (aux > aux2) swap(aux, aux2);
        cout << "S " << aux << " " << aux2 << " " << aux3 << ln;
    }

    
    return 0;
}