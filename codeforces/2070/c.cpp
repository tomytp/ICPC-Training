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

bool is_valid(ll n, ll k, const string& s, const vector<ll>& a, ll thresh) {
    vector<bool> blue(n);
    vector<bool> red(n);
    
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'B' && a[i] > thresh) {
            blue[i] = true;
        } else if (s[i] == 'R' && a[i] > thresh) {
            red[i] = true;
        }
    }
    
    ll op = 0;
    ll i = 0;
    
    while (i < n) {
        if (!red[i]) {
            bool h_blue = false;
            ll j = i;
            
            while (j < n && !red[j]) {
                if (blue[j]) {
                    h_blue = true;
                }
                j++;
            }
            
            if (h_blue) {
                op++;
            }
            
            i = j;
        } else i++;
    }
    
    return op <= k;
}

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    v64 a(n);
    forn(i, 0, n) cin >> a[i];
    
    ll l = 0;
    ll r = *max_element(a.begin(), a.end());
    
    while (l < r) {
        ll mid = l + (r - l) / 2;
        
        if (is_valid(n, k, s, a, mid)) r = mid;
        else l = mid + 1;
    }
    
    cout << l << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}