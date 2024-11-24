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
#define F_ if(!D_)ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

void solve() {
    ll n; cin >> n;
    vector<bool> v(n + 1);
    ll inp, r = 2, q = 0, prev = 0, zeros = 0;
    while(zeros == 0 && q < n && r <= n) {
        cout << "? 1 " << r << ln;
        cout.flush();
        cin >> inp;
        q++;
        if (inp) {
            v[r] = true;
            forn(i, 1, r-inp) {
                v[i] = true;
            }
            zeros = inp;
            prev = inp;
        }

        r++;
    }

    if (zeros == 0) {
        cout << "! IMPOSSIBLE\n";
        cout.flush();
        return;
    }
    
    while (q < n && r <= n) {
        cout << "? 1 " << r << ln;
        cout.flush();
        cin >> inp;
        q++;

        if (inp == prev) {
            zeros++;
        } else {
            v[r] = true;
            prev = inp;
        }

        r++;
    }
    cout << "! ";
    forn(i, 1, n+1) {
        cout << (v[i]? 1 : 0);
    }
    cout << ln;
    cout.flush();
}

int main(){
    F_;
    ll t; cin >> t;
    while(t--) solve();
    P_; return 0;
}