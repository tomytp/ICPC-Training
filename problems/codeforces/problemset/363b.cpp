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
    ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    ll sum = 0, min_sum = 0, idx = 0;
    forn(i, 0, k) {
        sum += v[i];
    }
    min_sum = sum;
    forn(i, k, n) {
        sum += v[i];
        sum -= v[i-k];
        if (sum < min_sum) {
            min_sum = sum;
            idx = i - (k-1);
        }
    }
    cout << idx+1 << ln;
    P_; return 0;
}