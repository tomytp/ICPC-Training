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
    _;
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    v64 bits(32);
    forn(i, 0, n) {
        bitset<32> bt(v[i]);
        forn(j, 0, 32) if (bt[j]) bits[j]++;
    }
    forn(i, 0, n) {
        ll out = 0;
        for (ll j = 31; j >= 0; j--) {
            out <<= 1;
            if (bits[j] > 0) {
                bits[j]--;
                out |= 1;
            }
        }
        cout << out << " ";
    }
    cout << ln;
    return 0;
}