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

struct event {
    ll s, e, c, p;

    bool operator < (const event o) const {
		if (e < o.e) return true;
        if (e > o.e) return false;
        if (s < o.s) return true;
        if (s > o.s) return false;
        return p < o.p;
	}
};

int main(){
    _;
    ll n; cin >> n;
    set<ll> line;
    vector<vector<tuple<ll, ll, ll>>> v(n);
    vector<event> q;
    forn(i, 0, n) {
        ll a, b, c; cin >> a >> b >> c;
        v[i].emplace_back(a, b, c);
        line.insert(a);
        line.insert(b);
    }
    map<ll, ll> conv;
    ll idx = 0;
    for (auto& e : line) conv[e] = idx++;

    forn(i, 0, n) {
        for (auto &[a, b, c] : v[i]) {
            a = conv[a];
            b = conv[b];
        }
    }
    
    return 0;
}