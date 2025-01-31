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

ll ask(ll i, ll j) {
    cout << "? " << i << " " << j << ln;
    cout.flush();
    ll ans; cin >> ans;
    return ans;
}

v64 opt = {4, 8, 15, 16, 23, 42};
set<ll> s = {4, 8, 15, 16, 23, 42};
v64 ans = {0, 0, 0, 0, 0, 0};

int main(){
    F_;
    ll a, b, c, d;
    a = ask(1, 2);
    b = ask(2, 3);
    c = ask(4, 5);
    d = ask(5, 6);
    
    forn(i, 0, 6) {
        if (a % opt[i] == 0 && b % opt[i] == 0 && s.find(a / opt[i]) != s.end() && s.find(b / opt[i]) != s.end() && a/opt[i] != opt[i] && b/opt[i] != opt[i]) {
            ans[0] = a / opt[i];
            ans[1] = opt[i];
            ans[2] = b / opt[i];
        }
    }
    
    forn(i, 0, 6) {
        if (c % opt[i] == 0 && d % opt[i] == 0 && s.find(c / opt[i]) != s.end() && s.find(d / opt[i]) != s.end() && c/opt[i] != opt[i] && d/opt[i] != opt[i]) {
            ans[3] = c / opt[i];
            ans[4] = opt[i];
            ans[5] = d / opt[i];
        }
    }

    cout << "! ";
    forn(i, 0, 6) cout << ans[i] << " \n"[i==5];
    P_; return 0;
}