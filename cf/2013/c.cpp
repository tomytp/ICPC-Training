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

bool query(string s) {
    ll ans;
    cout << "? " << s << ln;
    cout.flush();
    cin  >> ans;
    return ans == 1;
}

void solve() {
    ll n; cin >> n;
    string s = "";
    
    while (s.size() < n) {
        if (query(s + '1')) {
            s += '1';
        } else if (query(s + '0')) {
            s += '0';
        } else {
            break;
        }
    }

    while (s.size() < n) {
        if (query('1' + s)) {
            s = '1' + s;
        } else {
            s = '0' + s; 
        }
    }

    cout << "! " << s << ln;
    cout.flush();
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}