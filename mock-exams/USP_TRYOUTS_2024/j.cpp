#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


int main() {
    fast_cin();
    ll n; cin >> n;
    v64 vec(n);
    forn(i, 0, n) {
        cin >> vec[i];
    }
    sort(vec.rbegin(), vec.rend());
    ll maxv =0, maxp =0, rv=0;
    forn(i, 0, n) {
        if((i+1)*vec[i] > maxv) {
            maxv = (i+1)*vec[i];
            maxp=vec[i];
            rv = (i+1)*vec[i];
        } 
    }
    cout << maxp << " " << rv << ln;
}