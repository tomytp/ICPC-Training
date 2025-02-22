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
    ll n, m; cin >> n >> m;
    vector<ll> v;
    forn(i, 0, n) {
        ll curr = 0;
        forn(j, 0, m) {
            char aux; cin >> aux;
            curr <<= 1;
            if (aux == 'Y'){
                curr |= 1;
            } 
        }
        v.push_back(curr);
    }
    ll bv = -1, ba, bb;
    ll mask = (1<<m) -1;

    forn(i, 0, n) {
        forn(j, i+1, n) {
            ll or_ = v[i] | v[j];
            ll and_ = v[i] & v[j];
            if (or_ != mask) continue;
            if (__builtin_popcountll(and_) > bv) {
                bv = __builtin_popcountll(and_);
                ba = i;
                bb = j;
            }
        }
    }
    if (bv == -1) {
        cout << "No\n";
    } else {
        cout << ba + 1 << " " << bb + 1 << ln;
    }
    return 0;
}