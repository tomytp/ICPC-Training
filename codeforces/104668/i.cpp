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

const ll MAXN = 5'000'005;

v64 resp(MAXN,0);
v64 cum_sum(MAXN, 0);

void pre_calc(){
    forn(a, 1, (MAXN/2 + 1))
    forn(b, 1, min(a,MAXN/a))
    forn(c, 1, min(b, MAXN/(a*b)))
        resp[a*b*c]++;
    
    forn(i,1,MAXN){
        cum_sum[i] = cum_sum[i-1] + resp[i];
    }    
}

void solve(){
    ll n; cin >> n;
    cout << cum_sum[n] << ln;
}

int main(){
    _;
    pre_calc();
    // forn(i,0,30) cout << i << " \t " << resp[i] << "\t " << cum_sum[i] << ln;
    ll t; cin >> t;
    while(t--) solve();
}