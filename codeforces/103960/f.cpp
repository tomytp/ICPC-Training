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
    ll n, c; cin >> n >> c;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];

    map<string, ll> mp;
    forn(i, 0, n) {
        ll idx = v[i].find('*');
        forn(j, 0, 26) {
            v[i][idx] = 'a' + j;
            mp[v[i]]++;
        }
    }

    ll max_v = 0;
    string max_s = "";
    for (auto &[k, vc] : mp) {
        if (vc > max_v || (vc == max_v && k < max_s)) {
            max_v = vc;
            max_s = k;
        }
    }
    cout << max_s << " " << max_v << ln;
    return 0;
}