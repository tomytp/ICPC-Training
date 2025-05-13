#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
#define _ (void)0
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
#define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct bit {
    v64 ft;
    bit(ll n) {
        ft.assign(n + 2, 0);
    }
    ll rsq(ll i) {
        ll s = 0;
        for (; i; i -= i & -i) s += ft[i];
        return s;
    }
    void add(ll i, ll v) {
        for (; i < (ll)ft.size(); i += i & -i) ft[i] += v;
    }
};

ll parity(v64 &v, ll mx) {
    bit b(mx);
    ll p = 0;
    forn(i, 0, (ll)v.size()) {
        ll x = v[i];
        p ^= ((b.rsq(mx) - b.rsq(x)) & 1LL);
        b.add(x, 1);
    }
    return p;
}

v64 merge(v64 &evens, v64 &odds, ll n) {
    v64 ans;
    forn(i, 0, n / 2) {
        ans.push_back(evens[i]);
        ans.push_back(odds[i]);
    }

    if (n & 1) {
        ans.push_back(evens.back());
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    v64 even, odd;
    forn(i, 0, n) {
        ll x;
        cin >> x;
        if (i & 1) odd.push_back(x);
        else even.push_back(x);
    }

    v64 sorted_even = even, sorted_odd = odd;

    sort(sorted_even.begin(), sorted_even.end());
    sort(sorted_odd.begin(), sorted_odd.end());

    ll even_parity = parity(even, n);
    ll odd_parity = parity(odd, n);

    v64 best = merge(sorted_even, sorted_odd, n);
    if (even_parity != odd_parity) {
        v64 cand;
        bool set = false;
        if (sorted_even.size() >= 2) {
            v64 tmp = sorted_even;
            swap(tmp[tmp.size() - 2], tmp.back());
            cand = merge(tmp, sorted_odd, n);
            set = true;
        }
        if (sorted_odd.size() >= 2) {
            v64 tmp = sorted_odd;
            swap(tmp[tmp.size() - 2], tmp.back());
            v64 c2 = merge(sorted_even, tmp, n);
            if (!set || c2 < cand)
                cand = c2;
        }
        best = cand;
    }
    forn(i, 0, n) cout << best[i] << " \n"[i==n-1];
}

int main()
{
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
