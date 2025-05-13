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

int main(){
    _;
	ld tf, vf, hf, td, vd, hd;
	
	cin >> tf >> vf >> hf >> td >> vd >> hd;
	
	td -= tf;

	ld tempo_frisbe_chao = sqrt(2*hf);
	ld dist_frisbe_caiu_chao = vf*tempo_frisbe_chao;
	ld tempo_dog_chao = dist_frisbe_caiu_chao/vd;
	
	ld ty = sqrt(2*(hf-hd));
	ld tx = (td*vd)/(vd-vf);


	if(vd <= vf){
		debug(1);
		cout << setprecision(20) << fixed << td + td + 2*(vf*sqrt(2*hf))/vd << ln;
		return 0;
	}


	ld ty = sqrt(2*(hf-hd));
	ld tx = (td*vd)/(vd-vf);

	if(tx >= ty){
		debug(2);
		cout << setprecision(20) << fixed << tf + 2*tx <<ln;
		return 0;
	}

	debug(3);
	cout << setprecision(20) << fixed << tf + ty + vf*ty/vd << ln;
    return 0;
}