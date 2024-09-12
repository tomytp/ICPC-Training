#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<p64, null_type,less<p64>, rb_tree_tag,tree_order_statistics_node_update> 
#define dbg(x) cout << #x << " = " << x << ln

int main() {
    FAST_CIN;
    ll n, m, k; cin >> n >> m >> k;
    v64 pess(n);
    v64 apar(m);
    forn(i, 0, n) cin >> pess[i];
    forn(i, 0, m) cin >> apar[i];
    sort(pess.begin(), pess.end());
    sort(apar.begin(), apar.end());
    ll p = 0, a = 0, tot = 0;
    while(p < pess.size() && a < apar.size()) {
        if (apar[a] >= pess[p] - k && apar[a] <= pess[p] + k) {
            tot++;
            a++;
            p++;
        } else if (apar[a] <= pess[p] - k) {
            a++;
        } else {
            p++;
        }
    }
    cout << tot << ln;
}