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
typedef long double ld;
const ld ep = 0.0000001;

int main(){
    _;
	ld tf, vf, hf, td, vd, hd;
	
	cin >> tf >> vf >> hf >> td >> vd >> hd;
	
	td -= tf;
	
	ld t_queda = sqrt(2*hf);

	if(vd <= vf){
		cout << setprecision(20) << fixed << tf + td + 2*(vf*t_queda)/vd << ln;
		return 0;
	}

	ld l = 0;
	ld r = 2'000'000'000;
	ll n_it = 100000;
	
	ld v_vd = sqrt(2*3*hd);
	ld t_dogalto = v_vd/3;

	ld t;
	forn(h,0,n_it){
		t = (l+r)/2;
		ld xd,yd, xf, yf;
		xd = (t - td)*vd;

		if(t > t_dogalto + td -ep){
			yd = hd;
		}else{
			yd = v_vd*(t-td) - 3*(t-td)*(t-td)/2;
		}

		xf = min(t,t_queda)*vf;
		yf = hf - t*t/2;
		if(xd >= xf && yf <= yd){
			r = t;
		}else{
			l = t;
		}
	}

	ld dist_andada_frisbe = vf*min(t, t_queda);

	ld resp = t + dist_andada_frisbe/vd;
	
	cout << setprecision(20) << fixed << tf + resp << ln;
    return 0;
}