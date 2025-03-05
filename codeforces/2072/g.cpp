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

ll rev(ll n, ll p) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    if (p > n) return n;
    
    vector<ll> digits;
    ll temp = n;
    while (temp > 0) {
        digits.push_back(temp % p);
        temp /= p;
    }
    
    ll result = 0;
    for (int digit : digits) {
        result = result * p + digit;
    }
    
    return result;
}

int main() {
    _;
    
    int t;
    cin >> t;
    
    const ll MOD = 1000000007; // 10^9 + 7
    
    while (t--) {
        ll n, k;
        cin >> n >> k;
        
        // Handle special cases
        if (n == 0) {
            cout << "0" << endl;
            continue;
        }
        
        if (n == 1) {
            // For n = 1, rev(1, p) = 1 for all p
            cout << (k - 1) % MOD << endl;
            continue;
        }
        
        ll sum = 0;
        
        // For bases 2 to min(k, n), calculate rev(n, p) individually
        for (ll p = 2; p <= min(k, n); p++) {
            sum = (sum + rev(n, p)) % MOD;
        }
        
        // For bases > n up to k, rev(n, p) = n
        if (k > n) {
            // Calculate (k - n) % MOD to avoid overflow
            ll count = (k - n) % MOD;
            // Add (n * count) % MOD to the sum
            sum = (sum + (n % MOD) * count % MOD) % MOD;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}