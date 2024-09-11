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
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<p64, null_type,less<p64>, rb_tree_tag,tree_order_statistics_node_update> 
#define dbg(x) cout << #x << " = " << x << ln

v64 vec;

int main() {
    FAST_CIN;
    ll n, q; cin >> n >> q;
    ordered_set s;
    vec.resize(n);
    forn(i, 0, n) {
        cin >> vec[i];
        s.insert(make_pair(vec[i],i));
    }
    
    forn(i, 0, q) {
        char t; cin >> t;
        if (t == '!') {
            ll k, x; cin >> k >> x;
            k--;
            s.erase(make_pair(vec[k], k));
            vec[k] = x;
            s.insert(make_pair(vec[k], k));
        } else {
            ll a, b; cin >> a >> b;
            ll start = s.order_of_key(make_pair(a,-1));
            ll end = s.order_of_key(make_pair(b,1000000000000));
            cout << (end - start) << ln;
        }
    }
}