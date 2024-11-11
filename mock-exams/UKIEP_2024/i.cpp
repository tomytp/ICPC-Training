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
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


int main() {
    fast_cin();
    ll n, m, floor; cin >> n >> m;
    floor = m/n;
    forn(i,0,n-1){
        cout << "1 1 "<< floor -1 << " " << floor << ln;
    }
    cout << n << " " << m-n+1<< " 1 " << m-(n-1)*floor << ln;

}