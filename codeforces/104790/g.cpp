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
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ll c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;

	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
    bool operator < (const line l) const {
		if (!(p == l.p)) return p < l.p;
		return q < l.q;
	}
    bool operator == (const line l) const {
		return p == l.p and q == l.q;
	}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

int main(){
    _; pt a, b, c, d; cin >> a >> b >> c >> d;
    if(a+c == b+d){
        a = a*2;
        b = b*2;
        c = c*2;
        d = d*2;
        pt center = (a+c)*(1/2);
        a = a - center;
        b = b - center;
        c = c - center;
        d = d - center;

        if((a-c)*(b-d) != 0){
            if((b-a)*(d-a) != 0){
                cout << "parallelogram" << ln;
                return 0;
            }
            cout << "rectangle" << ln;
            return 0;
        }
        if((b-a)*(d-a) != 0){
            cout << "rhombus" << ln;
            return 0;
        }
        cout << "square" << ln;
        return 0;
    }

    if((dist2(a,b) == dist2(a,d) and dist2(c,b) == dist2(c,d)) or (dist2(c,d) == dist2(a,d) and dist2(c,b) == dist2(a,b))){
        cout << "kite" << ln;
        return 0;
    }

    if((((b-a)^(d-c)) == 0) or (((b-c)^(d-a)) == 0)){
        cout << "trapezium" << ln;
        return 0;
    }

    cout << "none" << ln;
    return 0;
}