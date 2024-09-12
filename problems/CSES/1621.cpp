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
    ll n; cin >> n;
    set<ll> s;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        s.insert(aux);
    }
    cout << s.size() << ln;
}