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

void solve() {
    ll n; cin >> n;
    v64 v;
    set<ll> game;
    forn(i, 0, n) {
        ll aux; cin >> aux;
        game.insert(aux);
    }
    n = game.size();
    ll prev = 0;
    for (auto x : game) {
        v.push_back(x - prev);
        prev = x;
    }

    if (v[0] != 1) {
        cout << "Alice\n";
        return;
    }

    ll ones = 0;
    forn(i, 0, n-1) {
        if (v[i] != 1) break;
        ones++;
    }
    if (ones & 1) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}