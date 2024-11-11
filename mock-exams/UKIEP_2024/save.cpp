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

const ll neutral = 0;
#define comp(a,b) (((a)+(b))%3)

struct BIT {
    vv64 ft;
    
    BIT(ll n, ll m) {
        ft.assign(n + 1, v64(m+1, 0));
    } 
    ll rsq(ll i, ll j) {
        ll sum = 0, _j = j;
        while( i> 0) {
            j= _j;
            while (j > 0) {
                sum = comp(sum, ft[i][j]);
                j -= (j & -j);
            }
            i -= (i & -i);
        }
        return sum;
    }

    void update(ll i, ll j, ll v) {
        ll _j = j;
        while(i < (ll) ft.size()) {
            j = _j;
            ft[i][j] = comp(v, ft[i][j]);
            j += (j & -j);
        }
        i  += (i & -i);
    }
};

int main() {
    fast_cin();
    ll n; cin >> n;

}