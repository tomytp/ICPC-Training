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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

// int main() {
//     ordered_set s;
//     s.find_by_order(position);
//     s.order_of_key(value);
// }

int main(){
    _; 
    ll n; cin >> n;
    ll king = 1, curr = 2;
    vector<set<ll>> g(n);
    ordered_set s;
    s.insert(1);
    forn(i, 0, n) {
        ll type, val; cin >> type >> val;
        if (type == 1) {
            if (g[val].size()) {
                ll sib = *(--g[val].end());
                ll sib_pos = s.order_of_key(sib);
                
            }
        }
    }


    return 0;
}