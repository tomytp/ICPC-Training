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
const ll MOD = 1000000007;

ll mult(ll a, ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}

ll sum(ll a, ll b){
    return ((a%MOD)+(b%MOD))%MOD;
}

ll sub(ll a, ll b){
    return ((a%MOD) - (b%MOD) + MOD)%MOD;
}

ll pot(ll a, ll b){
    ll expo=1, prod=a;
    b = b % (MOD-1);
    a = a % MOD;

    while(b>=1){
        if(b%2 == 1) expo = mult(expo,prod);
        prod = mult(prod,prod);
        b = b/2;
    }
    
    return expo;
}

ll inv_mod(ll a){
    return pot(a, MOD-2);
}

int main(){
    _;
    ll n, k, d;
    cin >> n >> k >> d;
    v64 dp0(n + 1), dp1(n+1);
    dp0[0] = 1;

    forn(i, 0, n+1) {
        forn(j, 1, k+1) {
            if (i-j < 0) break;

            dp1[i] = sum(dp1[i], dp1[i-j]);
            if (j < d) {
                dp0[i] = sum(dp0[i], dp0[i-j]);
            } else {
                dp1[i] = sum(dp1[i], dp0[i-j]);
            }
        }
    }
    // forn(i, 1, n+1) cout << dp0[i] << " \n"[i==n];
    // forn(i, 1, n+1) cout << dp1[i] << " \n"[i==n];
    cout << dp1[n] << ln;
    return 0;
}