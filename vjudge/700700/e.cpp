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
    ll n, m, k; cin >> n >> m >> k;
    v64 pessoas(n), apartamentos(m);
    forn(i, 0, n) cin >> pessoas[i];
    forn(i, 0, m) cin >> apartamentos[i];

    sort(pessoas.begin(), pessoas.end());
    sort(apartamentos.begin(), apartamentos.end());

    ll ap = 0, pes = 0;
    ll ans = 0;
    while (ap < m && pes < n) {
        if (pessoas[pes] > apartamentos[ap] + k) {
            ap++;
        } else if (pessoas[pes] < apartamentos[ap] - k) {
            pes++;
        } else {
            ans++;
            ap++;
            pes++;
        }
    }

    cout << ans << ln;
    return 0;
}