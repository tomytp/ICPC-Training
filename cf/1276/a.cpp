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
    ll n = s.size();
    vector<ll> v;
    forn(i, 0, n) {
        bool has_one = false, has_two = false;
        if (i < n-2) has_one = s.substr(i, 3) == "one";
        if (i >= 2) has_two = s.substr(i-2, 3) == "two";
        
        if (has_one && !has_two) {
            v.push_back(i+1);
        }
        if (has_two && !has_one) {
            v.push_back(i-1);
        }
        if (has_one && has_two) {
            v.push_back(i);
        }

                
    }
    cout << v.size() << ln;
    for (auto& x : v) {
        cout << x + 1<< " ";
    }
    cout << ln;
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}