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


ll calculate_mex(const vector<ll>& arr) {
    set<ll> s;
    for (ll x : arr) {
        if (x >= 0) {
            s.insert(x);
        }
    }
    ll mex_val = 0;
    while (s.count(mex_val)) {
        mex_val++;
    }
    return mex_val;
}

bool is_magical(const vector<ll>& s) {
    ll n = s.size();
    if (n <= 1) {
        return true;
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll current_min = s[0];
        for (ll j = 1; j <= i; ++j) {
            current_min = min(current_min, s[j]);
        }
        vector<ll> suffix;
        for (ll j = i + 1; j < n; ++j) {
            suffix.push_back(s[j]);
        }
        if (current_min < calculate_mex(suffix)) {
            return false;
        }
    }
    return true;
}

ll solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll max_len = 0;
    for (ll i = 0; i < (1 << n); ++i) {
        vector<ll> subsequence;
        for (ll j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subsequence.push_back(a[j]);
            }
        }
        if (is_magical(subsequence)) {
            max_len = max(max_len, (ll)subsequence.size());
        }
    }
    return max_len;
}

ll main() {
    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}