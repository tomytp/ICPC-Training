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
    string s; cin >> s;

    if (s.size() == 1) {
        cout << -1 << ln;
        return;
    }

    if (s.size() == 2) {
        cout << (s[0] == s[1] ? s : "-1") << ln;
        return;
    }

    forn(i, 1, s.size()) {
        if (s[i] == s[i-1]) {
            cout << s[i-1] << s[i] << ln;
            return;
        }
    }

    forn(i, 2, s.size()) {
        set<ll> st = {s[i], s[i-1], s[i-2]};
        if (st.size() == 3) {
            cout << s[i-2] << s[i-1] << s[i] << ln;
            return;
        }
    }
    cout << -1 << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}