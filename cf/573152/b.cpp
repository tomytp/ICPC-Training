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

ll find(vector<ll>& v, ll money) {
    ll l = 0, r = v.size() - 1, ans = -1;

    while (l <= r) {
        ll mid = l + (r-l) / 2;

        if (v[mid] <= money) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid -1;
        }
    }

    return ans + 1;
}

int main(){
    F_;
    ll n; cin >> n;
    vector<ll> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll q; cin >> q;
    forn(i, 0, q) {
        ll money; cin >> money;
        cout << find(v, money) << ln;
    }

    P_; return 0;
}