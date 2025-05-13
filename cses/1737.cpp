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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, UPD = 1e5+10, LOG = 18;
const int MAXS = 2*MAX+UPD*LOG;

namespace perseg {
	ll seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	ll n;
    v64 *v;

	ll build(int p, int l, int r) {
		if (l == r) return seg[p] = (*v)[l];
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(int n2, v64& v2) {
		n = n2, v = &v2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	ll query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	ll query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	ll update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) + seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] + update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};


int main(){
    _;
    ll n; ll q;
    cin >> n >> q;
    v64 vec(n);

    v64 versions;
    
    
    versions.push_back(0);
    
    forn(i,0,n) cin >> vec[i];
    
    perseg::build((ll) vec.size(), vec);

    forn(i,0,q){
        ll t; cin >> t;
        if(t == 1){
            ll k, a, x;
            cin >> k >> a >> x;
            ll new_v = perseg::update(--a, x, versions[k-1]);
            versions[k-1] = new_v;
        }
        if(t == 2){
            ll k, a, b;
            cin >> k >> a >> b;
            a--; b--;
            ll aux = perseg::query(a, b, versions[k-1]);
            cout << aux << ln;
        }
        if(t == 3){
            ll k;
            cin >> k;
            versions.push_back(versions[k-1]);
        }
    }

    return 0;
}