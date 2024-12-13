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
    vv64 m(4, v64(n));
    forn(i, 0, n/2) {
        m[0][2*i] = i % 2;
        m[0][2*i + 1] = i % 2;

        m[1][2*i] = (i % 2) + 1;
        m[1][2*i + 1] = (i % 2) + 1;
    }

    if (n & 1) {
        m[0][n-1] = 3;
        m[1][n-1] = 3;
    }

    m[2][0] = 8;
    m[3][0] = 8;

    forn(i, 0, n/2 - !(n&1)) {
        m[2][2*i + 2] = (i % 2) + 4;
        m[2][2*i + 1] = (i % 2) + 4;

        m[3][2*i + 2] = (i % 2) + 6;
        m[3][2*i + 1] = (i % 2) + 6;
    }

    if (!(n&1)) {
        m[2][n-1] = 9;
        m[3][n-1] = 9;
    }


    forn(i, 0, 4) {
        forn (j, 0, n) {
            cout << (char)('a' + m[i][j]);
        }
        cout << ln;
    }



    P_; return 0;
}