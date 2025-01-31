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

ll get_sum(ll a, ll b) {
    cout << "? " << a+1 << " " << b+1 << ln;
    cout.flush();
    ll sum;
    cin >> sum;
    return sum;
}

int main(){
    F_;
    ll n; cin >> n;
    ll s1, s2, s3;
    s1 = get_sum(0, 1);
    s2 = get_sum(1, 2);
    s3 = get_sum(0, 2);
    v64 v(n);
    v[1] = (s1 + s2 - s3) / 2;
    v[0] = s1 - v[1];
    v[2] = s3 - v[0];
    forn(i, 3, n) {
        s1 = get_sum(0, i);
        v[i] = s1 - v[0];
    }
    cout << "! ";
    forn(i, 0, n) {
        cout << v[i] << " \n"[i==n-1];
    }
    cout.flush();
    P_; return 0;
}