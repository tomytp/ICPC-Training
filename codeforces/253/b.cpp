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

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    _;
    ll n; cin >> n;
    v64 freq(5000, 0);
    forn(i, 0, n) {
        ll aux; cin >> aux;
        freq[aux]++;
    }
    partial_sum(freq.begin(), freq.end(), freq.begin());

    ll ans = INF;
    forn(i, 1, 5000) {
        ll curr = 0;
        if (i < 2500) curr += freq[4999] - freq[2*i];
        curr += freq[i-1];
        ans = min(ans, curr);
    }
    cout << ans << ln;

    return 0;
}