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

int main(){
    _;
    ll n, m; cin >> n >> m;
    v64 huts(n);
    v64 shops(m);

    forn(i,0,n) cin >> huts[i];
    forn(i,0,m) cin >> shops[i];

    sort(shops.begin(), shops.end());

    v64 near_shop(n);

    forn(i,0,n){
        auto it = lower_bound(shops.begin(), shops.end(), 100*i);
        
        ll dir = INF;
        ll esq = -INF; 

        if(it != shops.end()) dir = *it;
        if(it != shops.begin()) esq = *(--it);
        
        near_shop[i] = min(100*i - esq, dir - 100*i);
    }

    // forn(i,0,n) cout << near_shop[i] << " \n"[i == n-1];
    
    v64 baixo(n);
    v64 cima(n);

    forn(i,0,n){
        baixo[i] = 100*i - near_shop[i];
        cima[i] = 100*i + near_shop[i];
    }

    multiset<ll> cota_baixo;
    multiset<ll> cota_cima;

    ll p1 = 0;
    ll p2 = 0;
    ll curr_people = 0;

    if(near_shop[p2] != 0) curr_people = huts[p2]; 

    cota_baixo.insert(baixo[p2]);
    cota_cima.insert(cima[p2]);

    debug(1);
    
    ll max_people = curr_people; 
    
    while(p2 < n-1){
        debug(p1); 
        debug(p2);
        if(p1 > p2){
            p2++;
            curr_people = 0;
            if(near_shop[p2] != 0) curr_people = huts[p2]; 
            max_people = max(curr_people, max_people);
            cota_baixo.insert(baixo[p2]);
            cota_cima.insert(cima[p2]);
            continue;
        }
        ll lb = -INF;
        ll ub = INF;
        if(!cota_baixo.empty()) lb = *cota_baixo.rbegin() ;
        if(!cota_cima.empty())  ub = *cota_cima.begin();
         
        if(max(baixo[p2+1], lb) < min(cima[p2+1], ub)){
            p2++;
            cota_baixo.insert(baixo[p2]);
            cota_cima.insert(cima[p2]);
            curr_people += huts[p2];
            max_people = max(max_people, curr_people);
        }else{
            cota_baixo.erase(cota_baixo.find(baixo[p1]));
            cota_cima.erase(cota_cima.find(cima[p1]));
            curr_people -= huts[p1];
            p1++;
        }
        // :D
    }

    cout << max_people << ln;
    return 0;
}