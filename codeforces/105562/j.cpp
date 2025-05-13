#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define sq(x) ((x)*(ll)(x))

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll sqroot(ll a){
    ll l = 0;
    ll r = a;
    ll ans = -1;
    while (l <= r)
    {
        ll mid = (l+r)/2;
        if(mid*mid <= a){
            l = mid+1;
            ans = mid;
        }else{
            r = mid-1;
        }
    }

    return ans;
}

int main(){
    _; ll n; cin >> n;
    vector<ll> h(n), jib(n);
    map<ll, pt> ctr;
    map<ll, ll> name;

    forn(i, 0, n){
        pt aux; cin >> aux >> h[i];
        ctr[h[i]] = aux;
        name[h[i]] = i;
    }

    sort(h.rbegin(), h.rend());

    forn(i, 0, n){
        ll min_dist = h[i];
        forn(j, 0, i) {
            min_dist = min(min_dist, sqroot(dist2(ctr[h[i]], ctr[h[j]])));
        }
        jib[name[h[i]]] = min_dist;
    }

    forn(i, 0, n) cout << jib[i] << ln;
    return 0;
}