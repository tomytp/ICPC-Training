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

ll get_card(ll val, v64 v) {
    if (val < 10) {
        if (v[val]) return val;
        else return -1;
    }
    forn(i, 10, 14) {
        if (v[i]) return i;
    }
    return -1;
}

int main(){
    _;
    ll n; cin >> n;
    v64 v(14, 4);

    ll a, b; cin >> a >> b;
    v[a]--; v[b]--;
    ll john = min(10ll, a) + min(10ll, b);
    cin >> a >> b;
    v[a]--; v[b]--;
    ll mary = min(10ll, a) + min(10ll, b);

    forn(i, 0, n) {
        cin >> a;
        v[a]--;
        john += min(10ll, a);
        mary += min(10ll, a);
    }

    if (mary >= john) {
        ll val = 23 - mary;
        if (val < 10 && v[val]) {
            cout << val << ln;
            return 0;
        }
        if (val < 10 && !v[val]) {
            cout << -1 << ln;
            return 0;
        }

        forn(i, 10, 14) {
            if (v[i]) {
                cout << i << ln;
                return 0;
            }
        }
        cout << -1 << ln;
        return 0;
    }

    ll lower = 24 - john;
    ll upper = min(lower + john - mary, 11ll);
    forn(i, lower, upper) {
        if (get_card(i, v) != -1) {
            cout <<  get_card(i, v) << ln;
            return 0;
        }
    }
    cout << -1 << ln;
    return 0;
}