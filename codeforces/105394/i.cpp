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

struct querry{
    ll l, a, p;
};

ll ask(querry q, ll idx){
    debug(idx);
    ll aux = idx - q.p;
    if(aux < 0 || aux >= q.l) return 0;
    if(aux % 2 == 1) return 0;
    if(aux % 4 == 0) return +q.a;    
    if(aux % 4 == 2) return -q.a;
    assert(false);    
}

int main(){
    _;
    ll n; ll w;
    cin >> n >> w;
    
    vector<querry> querries;

    forn(i,0,n){
        char c; cin >> c;
        if(c == '!'){
            querry q;
            cin >> q.p >> q.l >> q.a;
            querries.push_back(q);
            continue;
        }
        ll resp = 0;
        ll idx; cin >> idx;
        for(auto q: querries){
            resp += ask(q, idx);
        }
        cout << resp << ln;
    }
    return 0;
}