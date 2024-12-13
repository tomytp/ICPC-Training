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
    ll n, m; cin >> n >> m;
    vv64 a(n, v64(m)), b(n, v64(m));
    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> a[i][j];
        }
    }
    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> b[i][j];
        }
    }
    forn(i, 0, n) {
        forn(j, 0, m) {
            if (a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
        }
    }
    forn(i, 0, n) {
        forn(j, 1, m) {
            if (a[i][j] <= a[i][j-1] || b[i][j] <= b[i][j-1]) {
                cout << "Impossible" << ln;
                return 0;
            }
        }
    }
    forn(j, 0, m) {
        forn(i, 1, n) {
            if (a[i][j] <= a[i-1][j] || b[i][j] <= b[i-1][j]) {
                cout << "Impossible" << ln;
                return 0;
            }
        }
    }
    cout << "Possible\n";

    P_; return 0;
}