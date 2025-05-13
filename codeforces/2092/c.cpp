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

int main(){
    _;
    
    int t;
    cin >> t;
    
    while(t--) {
        ll n;
        cin >> n;
        
        v64 a(n);
        forn(i, 0, n) cin >> a[i];
        
        ll odd_count = 0, sum = 0;
        
        for(ll i = 0; i < n; i++) {
            sum += a[i];
            if(a[i] % 2 == 1) {
                odd_count++;
            }
        }
        
        ll result;
        
        if(odd_count == 0 || odd_count == n) {
            result = *max_element(a.begin(), a.end());
        } else {
            ll dp[2];
            dp[0] = sum - odd_count;
            dp[1] = sum - (odd_count-1);
            
            result = max(dp[0], dp[1]);
        }
        
        cout << result << ln;
    }
    
    return 0;
}