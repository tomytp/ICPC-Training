#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

ll n, m; 
v64 a, b;

void solve() {
    cin >> n >> m;
    a.resize(n), b.resize(m);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, m) cin >> b[i];
    ll current = 0, tot = m;
    set<ll> closed;
    forn (i, 0, m) {
        auto p = b[i];
        if (closed.find(p) != closed.end()) {
            continue;
        }
        ll newp = current;
        while (a[newp] != p) {
            closed.insert(a[newp]);
            newp++;
        }
        tot += (newp - i) * 2;
        newp++;
        current = newp;
    }
    cout << tot << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
} 