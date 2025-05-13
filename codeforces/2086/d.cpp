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
const ll MOD = 998244353;
const ll MAX_N = 5e5 + 10;
const ll ALF = 26;

ll mult(ll a, ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}

ll add(ll a, ll b){
    return ((a%MOD)+(b%MOD))%MOD;
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

ll factorial[MAX_N], invFactorial[MAX_N];
ll dp[ALF+1][MAX_N];
ll letter_count[MAX_N];

void solve() {
    ll str_size = 0;
    
    for (int i = 1; i <= ALF; i++) {
        cin >> letter_count[i];
        str_size += letter_count[i];
    }
    
    ll halfSize = str_size / 2;
    
    dp[0][0] = 1;
    
    forn(i, 1, ALF+1) {
        forn(sum, 0, halfSize+1) {
            dp[i][sum] = dp[i-1][sum];
            
            ll previousSum = sum - letter_count[i];
            if (letter_count[i] > 0 && previousSum >= 0) {
                dp[i][sum] = add(dp[i][sum], dp[i-1][previousSum]);
            }
        }
    }
    
    ll result = mult(factorial[halfSize], factorial[str_size - halfSize]);
    result = mult(result, dp[ALF][halfSize]);
    
    forn (i, 1, ALF+1) {
        result = mult(result, invFactorial[letter_count[i]]);
    }
    
    cout << result << ln;
}

int main() {
    _;
    
    factorial[0] = invFactorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        factorial[i] = mult(factorial[i-1], i);
        invFactorial[i] = inv_mod(factorial[i]);
    }
    
    ll t;cin >> t;
    while(t--) solve();
    return 0;
}