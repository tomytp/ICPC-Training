#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define ln "\n"
#define sz(x) (ll) (x).size()
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln

#define ordered_set tree<p64, null_type,less<p64>, rb_tree_tag,tree_order_statistics_node_update> 

int main() {
    fast_cin();
    ll n; cin >> n;

    ordered_set s;

    forn(i, 1, n+1) {
        ll aux; cin >> aux;
        s.insert(make_pair(i, aux));
    }
    forn(i, 0, n) {
        ll aux; cin >> aux;
        auto it = s.find_by_order(aux - 1);
        cout << (*it).second << " ";
        s.erase(it);
    }
    cout << ln;
}