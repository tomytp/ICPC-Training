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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll N = 200'000;
v64 prox;
ll ask_counter = 0;

void pre_compute(ll n){
    prox.resize(n+1);
    forn(i,1,n+1){
        prox[i] = uniform(1,n);
    }
    
}

ll ask(ll c, ll r) {
    // cout << "? " << c << " " << r << ln;
    // cout.flush();
    // ll ans; cin >> ans; 
    ask_counter++;
    if(ask_counter > 1000){
        cout << "PERGUNTOU DE MAIS" << ln;
        forn(i,0,N) cout << prox[i] << " \n"[i==N-1];
        exit(0);
    }

    ll resp = r; 
    forn(i,0,c) resp = prox[resp];

    return resp;
}

bool solve(ll n){
    pre_compute(n);

    ll first = ask(n, n);
    ll t = sqrt(n) + 1;

    set<p64> visited;
    visited.insert({first, 0});
    ll curr = first;
    p64 last;
    forn(i, 1, t+4) {
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
    // debug(ciclo);
    ll new_ciclo = ciclo;
    while(new_ciclo <= pre_r) new_ciclo += ciclo;
    
    ll r_certo = ask(new_ciclo - pre_r, pre_r);
    
    if(ask(pre_r, r_certo) == pre_r){
        // cout << "Ok" << ln;
        return true;
    }

    // cout << "! " << pre_r << " " << r_certo << ln;

    forn(i,0,n) cout << prox[i] << " \n"[i==n-1];
    return false;
}

int main(){
    _;
    ll counter = 0;

    while(solve(N)){
        counter++;
        ask_counter = 0;
        cout << counter << ln;
    };

}