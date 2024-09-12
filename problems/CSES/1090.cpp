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
    ll n, x; cin >> n >> x;
    v64 vec(n);
    forn(i, 0, n) cin >> vec[i];
    sort(vec.begin(), vec.end());
    ll leve = 0, pesada = n-1, tot = 0;
    while(leve < pesada) {
        if (vec[leve] + vec[pesada] <= x) {
            leve++;
        }
        tot++;
        pesada--;
    }
    if (leve == pesada) tot++;
    cout << tot << ln;
}