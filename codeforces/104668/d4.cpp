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
const ld ep = 0.00000001;

int main(){
    _;
	ld tf, vf, hf, td, vd, hd;
	
	cin >> tf >> vf >> hf >> td >> vd >> hd;
	
	td -= tf;

	ld t_queda = sqrt(2*hf);
	ld x_queda = vf*t_queda;

	if((t_queda-td)*vd < x_queda + ep){
		ld resp = td + 2 * x_queda/vd;
		cout << setprecision(20) << fixed << tf + resp << ln;
		return 0;
	}

	ld tey = sqrt(2*(hf-hd));
	ld tex = td*vd/(vd-vf);

	ld resp = max(tey, tex)*(1 + vf/vd); 
	cout << setprecision(20) << fixed << tf + resp << ln;
	return 0;
}