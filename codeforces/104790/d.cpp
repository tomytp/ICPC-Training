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
    ll n, m; cin >> n >> m;
    vector<string> vec(n);
    forn(i, 0, n) cin >> vec[i];
    forn(i, 0, m) {
        map<char, ll> mp;
        forn(j, 0, n) {
            mp[vec[j][i]]++;
        }
        ll mx = 0;
        char c = 0;
        for (auto &[k, v] : mp) {
            if (v > mx) {
                mx = v;
                c = k;
            }
        }
        cout << c;
    }
    cout << ln;

    return 0;
}