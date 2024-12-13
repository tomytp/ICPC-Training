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

bool is_subsequence(string s, string t) {
    ll a = 0, b = 0, n = s.size(), m = t.size();
    while(a < n && b < m) {
        if (s[a] == t[b]) {
            a++; b++;
        } else {
            b++;
        }
    }
    return a == n;
}

void solve() {
    string s, t, p; cin >> s >> t >> p;

    if (!is_subsequence(s, t)) {
        cout << "NO" << ln;
        return;
    }

    map<char, ll> has;
    forn(i, 0, s.size()) {
        has[s[i]]++;
    }
    forn(i, 0, p.size()) {
        has[p[i]]++;
    }
    forn(i, 0, t.size()) {
        if (!has[t[i]]) {
            cout << "NO" << ln;
            return;
        }
        has[t[i]]--;
    }
    cout << "YES\n";

}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}