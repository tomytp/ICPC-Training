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

//czddeneeeemigec
//ccddezeeeenmige
//ccddeeeeeeznmig
//ccddeeeeeegznmi
//ccddeeeeeegiznm
//ccddeeeeeegimzn
//ccddeeeeeegimnz

//bacba
//cccba

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    string cp = s;
    sort(cp.begin(), cp.end());
    string max_rev = s;
    vector<char> vals;
    vector<ll> idx;
    for (ll i = n-2; i >= 0; i--) max_rev[i] = max(max_rev[i], max_rev[i+1]);
    
    forn(i, 0, n) {
        if (s[i] == max_rev[i]) {
            vals.push_back(s[i]);
            idx.push_back(i);
        }
    }
    
    reverse(vals.begin(), vals.end());
    forn(i, 0, idx.size()) {
        s[idx[i]] = vals[i];
    }

    if (s != cp) {
        cout << -1 << ln;
        return;
    }
    ll count = 0;
    forn(i,0,vals.size()){
        if(vals[i] == cp.back()) count++;
    }

    cout << idx.size() - count << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}