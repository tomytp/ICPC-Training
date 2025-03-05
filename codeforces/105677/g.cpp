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
    ll r; cin >> r;
    ll n; cin >> n;
    v64 moves(n);
    ll a = 0, b = r;
    forn(i, 0, n) {
        cin >> moves[i];
        a += moves[i];
        b += moves[i];
        a = min(a, r);
        a = max(a, 0ll);
        b = min(b, r);
        b = max(b, 0ll);
    }
    if (a == b) {
        cout << a << ln;
    } else {
        cout << "uncertain" << ln;
    }
    return 0;
}