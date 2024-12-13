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

int main(){
    F_;
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    ll ans = 0;
    forn(i, 0, n-1) {
        if (a[i] == b[i]) continue;
        if (a[i+1] == b[i] && a[i+1] != b[i+1]) {
            swap(a[i], a[i+1]);
            ans++;
        } else {
            a[i] = b[i];
            ans++;
        }
    }
    if (a[n-1] != b[n-1]) ans++;

    cout << ans << ln;

    P_; return 0;
}