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

ll counter_ask = 0;

ll ask(ll c, ll r) {
    counter_ask++;
    assert(counter_ask < 1000);
    
    cout << "? " << c << " " << r << ln;
    cout.flush();

    ll ans; cin >> ans;
    return ans;
}

int main(){
    _;
    ll n; cin >> n;

    if(n == 1){
        cout << "! " << 1 << " " << 1 << ln;
        return 0;
    }
    
    ll first = ask(n, n);
    ll t = sqrt(n) + 1;

    set<p64> visited;

    visited.insert({first, 0});
    ll curr = first;
    p64 last;
    
    forn(i, 1, t) {
        // se n == 1 faz coisas
        curr = ask(1, curr);
        visited.insert({curr, i});
        last = {curr, i};
    }
    
    ll ciclo = 0;
    ll pre_r;

    while(true){
        curr = ask(t, curr);
        ciclo += t;
        
        auto it = visited.lower_bound({curr, 0});
        if(it != visited.end() && it->first == curr){
            ciclo += last.second - it->second;
            pre_r = it->first;
            break;
        }
    }
    
    debug(ciclo);

    ll new_ciclo = ciclo;
    while(new_ciclo <= pre_r) new_ciclo += ciclo;
    
    ll r_certo = ask(new_ciclo - pre_r, pre_r);
    debug(new_ciclo);
    assert((new_ciclo-pre_r) <= n);
    assert(ask(pre_r, r_certo) == pre_r);
 
    cout << "! " << pre_r << " " << r_certo << ln;
    return 0;
}