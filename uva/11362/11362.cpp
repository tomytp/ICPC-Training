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

struct node {
    map<char, node> children;
};

void solve() {
    ll n; cin >> n;
    vector<string> v(n);

    node trie;

    forn(i, 0, n) cin >> v[i];
    for (auto& s : v) {
        node *temp = &trie;
        for (auto& c : s) {
            temp = &temp->children[c];
        }
    }

    for (auto& s : v) {
        node *temp = &trie;
        for (auto& c : s) {
            temp = &temp->children[c];
        }
        if (temp->children.size()) {
            cout << "NO" << ln;
            return;
        }
    }
    cout << "YES\n";    
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}