#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll MOD1 = 1'000'000'007;
const ll MOD2 = 1'000'000'009;
const ll p1 = 7577;
const ll p2 = 7757;

v64 powp1;
v64 powp2;

struct hsh {
    ll x = 0, y = 0;

    hsh(char c) {
        x = c - 'a';
        y = c - 'a';
    }

    hsh(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

    hsh shift(ll t) {
        return hsh((x*powp1[t])%MOD1, (y*powp2[t])%MOD2);
    }
	bool operator < (const hsh p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
    hsh operator + (const hsh l) const { return hsh((x+l.x)%MOD1, (y+l.y)%MOD2); }
    hsh operator - (const hsh l) const { return hsh((MOD1 + x-l.x)%MOD1, (MOD2 + y-l.y)%MOD2); }
	hsh operator * (const ll c) const { return hsh((x*c)%MOD1, (y*c)%MOD2); }
    bool operator == (const hsh p) const {
		return x == p.x and y == p.y;
	}

};

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<hsh> pref_hash;


void build(ll n, string s){
    powp1.resize(n+1,1);
    powp2.resize(n+1,1);
    
    forn(i,1,n+1){
        powp1[i] = (powp1[i-1]*p1)%MOD1; 
        powp2[i] = (powp2[i-1]*p2)%MOD2;  
    }

    pref_hash.assign(n, hsh());
    pref_hash[0] = hsh(s[0]);
    forn(i,1,n){
        pref_hash[i] = pref_hash[i-1].shift(1) + hsh(s[i]);
    }
}

hsh sub_hash(ll l, ll r){
    if (l == 0) return pref_hash[r];
    return pref_hash[r] - pref_hash[l-1].shift(r-l+1);     
}

int main(){
    _;
    string s;
    cin >> s;
    ll n = s.size();

    build(n, s);
    ll min_cost = INF;

    forn(sz, 2, (n/2)+1) {
        ll mx = 0;
        map<hsh, ll> amount, when;
        forn(i, 0, n-sz+1) {
            hsh cur = sub_hash(i, i+sz-1);
            if (when.find(cur) == when.end() || when[cur] <= i) {
                amount[cur]++;
                mx = max(mx, amount[cur]);
                when[cur] = i+sz;
            }
        }
        debug(mx);
        debug(sz);
        min_cost = min(min_cost, n+1 - (mx-1)*(sz-1));
    }

    if (min_cost == INF) {
        min_cost = n+1;
    }
    cout << min_cost << ln;


    return 0;
}