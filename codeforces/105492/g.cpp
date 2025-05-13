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

ll resp = 0;

ll read(){
    string s; cin >> s;
    ll pow = 1, a = 0;
    for(auto it = s.rbegin(); it!= s.rend(); it++){
        char c = *it;
        if(c == '.') continue;
        a += pow*(c-'0');
        pow*= 10;
    }

    resp += a;
    return a%5;
}
int main(){
    _; ll n; cin >> n;
    v64 mod(n);
    forn(i, 0, n) mod[i] = read();

    ll count3 = 0, count4 = 0;
    forn(i, 0, n){
        if(mod[i] < 3) resp -= mod[i];
        if(mod[i] == 3) count3++;
        if(mod[i] == 4) count4++;
    }

    if(count3 <= count4){
        resp -= 2*count3;
        ll x = count4 - count3;
        resp -= 2*(x/3);
    } else {
        resp -= 2*count4;
        ll x = count3 - count4;
        resp -= (x/2);
    }

    if((resp%100) < 10){
        cout << resp/100 << ".0" << resp%100 << ln;
        return 0;
    }
    cout << resp/100 << "." << resp%100 << ln;

    return 0;
}