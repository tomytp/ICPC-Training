#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

ll n, k, q; 
vv64 v;

ll bin_down(ll region, ll val) {
    ll left = 0;
    ll right = n - 1;
    ll result = -1;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (v[mid][region] < val) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

ll bin_up(ll region, ll val) {
    ll left = 0;
    ll right = n - 1;
    ll result = n;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (v[mid][region] > val) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main(){
    F_;
    cin >> n >> k >> q;
    v.resize(n, v64(k));
    forn(i, 0, n) {
        forn(j, 0, k) {
            cin >> v[i][j];
        }
    }
    forn(i, 1, n) {
        forn(j, 0, k) {
            v[i][j] |= v[i-1][j];
        }
    }

    forn(qq, 0, q) {
        ll subq; cin >> subq;
        ll l = 0, r = n-1;
        ll region, val;
        char dir;
        forn (ss, 0, subq) {
            cin >> region >> dir >> val;
            region--;
            if (dir == '<') {
                r = min(r, bin_down(region, val));
            } else {
                l = max(l, bin_up(region, val));
            }
        }
        if (l <= r) {
            cout << l + 1 << ln;
        } else {
            cout << -1 << ln;
        }
    }

    P_; return 0;
}