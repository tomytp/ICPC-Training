#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln '\n'

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll big_neg = -1'000'000'000'000'000'000LL;

int main() {
    _;
    ll t; cin >> t;

    while (t--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;

        v64 a(n);
        forn(i, 0, n) cin >> a[i];

        ll base_max = -4e18;
        ll cur_sum = -4e18;

        forn(i, 0, n) {
            if (s[i] == '1') {
                ll v = a[i];
                cur_sum = (cur_sum < 0) ? v : cur_sum + v;
                base_max = max(base_max, cur_sum);
            } else cur_sum = -4e18;
        }

        if (base_max > k) {
            cout << "No\n";
            continue;
        }

        v64 ans = a;

        if (base_max == k) {
            forn(i, 0, n) if (s[i] == '0') ans[i] = big_neg;
            cout << "Yes\n";
            forn(i, 0, n) cout << ans[i] << (i + 1 == n ? ln : ' ');
            continue;
        }

        v64 left_suffix(n, 0), right_prefix(n, 0);

        ll seg_sum = 0, min_pref = 0;
        forn(i, 0, n) {
            if (s[i] == '1') {
                seg_sum += a[i];
                min_pref = min(min_pref, seg_sum);
            } else {
                left_suffix[i] = max(0LL, seg_sum - min_pref);
                seg_sum = 0;
                min_pref = 0;
            }
        }

        seg_sum = 0;
        min_pref = 0;
        for (ll i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                seg_sum += a[i];
                min_pref = min(min_pref, seg_sum);
            } else {
                right_prefix[i] = max(0LL, seg_sum - min_pref);
                seg_sum = 0;
                min_pref = 0;
            }
        }

        ll chosen = -1;
        ll chosen_val = 0;

        forn(i, 0, n) if (s[i] == '0') {
            ll rb = right_prefix[i];
            ll lb  = left_suffix[i];
            ll need = k - lb - rb;
            if (abs(need) <= 1'000'000'000'000'000'000LL) {
                chosen = i;
                chosen_val = need;
                break;
            }
        }

        if (chosen == -1) {
            cout << "No\n";
            continue;
        }

        forn(i, 0, n) {
            if (s[i] == '0')
                ans[i] = (i == chosen ? chosen_val : big_neg);
        }

        cout << "Yes\n";
        forn(i, 0, n) cout << ans[i] << (i + 1 == n ? ln : ' ');
    }

    return 0;
}
