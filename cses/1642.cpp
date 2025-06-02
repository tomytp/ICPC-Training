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

ll n_vals = 4;

int main(){
    _;
    ll n, x; cin >> n >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    map<ll, v64> mp;
    forn(i, 0, n) {
        ll comp = x - v[i];
        auto it = mp.find(comp);
        if (it != mp.end() && it->second.size() == 3) {

            return 0;
        }        
        mp[v[i]] = {i, };

        vector<pair<ll, v64>> to_add;
        for (auto &[k, val] : mp) {
            if (val.size() < n_vals) {
                auto nval = val;
                nval.push_back(i);
                to_add.emplace_back(k + v[i], nval);
            }
        }
        for (auto &[k, val] : to_add) {
            mp[k] = val;
        }
    }

    cout << "IMPOSSIBLE" << ln;

    return 0;
}