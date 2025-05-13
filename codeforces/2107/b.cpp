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

int main() { _;
    ll T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        ll n; ll k;
        cin >> n >> k;
        v64 a(n);
        ll sum = 0, mn = INF, mx = 0;
        forn(i,0,n) {
            cin >> a[i];
            sum += a[i];
            mn  = min(mn, a[i]);
            mx  = max(mx, a[i]);
        }
        ll diff = mx - mn;
        ll cnt_max = count(a.begin(), a.end(), mx);

        bool tom = false;

        if (k == 0) {
            if (diff == 1 && cnt_max == 1) tom = true;
        } else {
            if (diff >= k + 2) tom = false;
            else if (diff == k + 1 && cnt_max >= 2) tom = false;
            else tom = (sum & 1);
        }
        cout << (tom ? "Tom" : "Jerry") << ln;
    }
    return 0;
}