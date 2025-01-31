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

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define dgb dbg

const ll MAXN = 200005;
const ll MAXLOGN = 25;
ll n; 

ll m[MAXN][MAXLOGN];

void build(vector<long long>& v) {
    ll sz = v.size();
    
    forn(i, 0, sz) {
        m[i][0] = v[i];
    }
    
    for (ll j = 1; (1 << j) <= sz; j++) {
        for (ll i = 0; i + (1 << j) <= sz; i++) {
            m[i][j] = max(m[i][j-1], m[i + (1 << (j-1))][j-1]);
        }
    }
}

ll query(ll a, ll b) {
    ll j = __builtin_clzll(1) - __builtin_clzll(b - a + 1);
    return max(m[a][j], m[b - (1 << j) + 1][j]);
}


ll bs(ll i, ll h) {
    ll l = i, r = n - 1;
    ll result = i;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (query(i, mid) <= h) {
            result = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return result;
}

void solve() {
    cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i]; 
    forn(i, 0, n) cin >> b[i];
    ll k; cin >> k;
    map<ll,ll> mp, fin;
    forn(i, 0, k) {
        ll aux; cin >> aux;
        mp[aux]++;
    }

    forn(i, 0, n) {
        if (b[i] > a[i]) {
            cout << "NO\n";
            return;
        }
    }

    build(b);

    forn(i, 0, n) {
        auto it = fin.find(b[i]);
        if ((it != fin.end() && it->second >= i) || b[i] == a[i]) continue;

        if (mp[b[i]] <= 0) {
            cout << "NO\n";
            return;
        }
        ll next = bs(i, b[i]);
        fin[b[i]] = next;
        mp[b[i]]--;
    }
    cout << "YES\n";
}

int main(){
    F_;
    ll t; cin >> t;
    while (t--) solve();
    P_; return 0;
}