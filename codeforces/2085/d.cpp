#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define _ ios_base::sync_with_stdio(false), cin.tie(NULL)

void solve() {
    ll n, k;
    cin >> n >> k;
    v64 d(n + 1);
    forn(i, 1, n+1) cin >> d[i];
    
    // Two arrays: curr for current state, next for next state
    // curr[j] = max deliciousness with j uneaten pieces after i-1 minutes
    v64 curr(n + 1, -1e18), next(n + 1, -1e18);
    curr[0] = 0;  // Base case: 0 deliciousness with 0 uneaten pieces
    
    // Process each minute
    for (ll i = 1; i <= n; i++) {
        fill(next.begin(), next.end(), -1e18);
        
        // For each possible number of uneaten pieces
        for (ll j = 0; j <= min(i*k, n); j++) {
            if (curr[j] == -1e18) continue;  // Invalid state
            
            // Option 1: Do nothing
            next[j] = max(next[j], curr[j]);
            
            // Option 2: Take the plate (only if we'll have time to eat all pieces)
            if (j + k <= n - i) {
                next[j + k] = max(next[j + k], curr[j] + d[i]);
            }
            
            // Option 3: Eat one piece
            if (j > 0) {
                next[j - 1] = max(next[j - 1], curr[j]);
            }
        }
        
        // Move to next state
        swap(curr, next);
    }
    
    // Final answer is maximum deliciousness with 0 uneaten pieces after n minutes
    cout << curr[0] << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}