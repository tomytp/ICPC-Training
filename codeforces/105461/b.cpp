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
const ll dez18 = 1'000'000'000'000'000'000ll;
const ll MAXDIG = 18;

ll testa(ll a, ll b, ll c, ll d){
    v64 digitos(10,0);
    digitos[7] = d;
    digitos[5] = c;
    digitos[9] = b/2;
    b = b%2;
    digitos[8] = a/3;
    a = a%3;

    if(b == 0){
        if(a == 1) digitos[2] = 1;
        if(a == 2) digitos[4] = 1;
    } else{
        if(a == 0) digitos[3] = 1;
        if(a == 1) digitos[6] = 1;
        if(a == 2){
            digitos[2] = 1;
            digitos[6] = 1;
        }
    }

    ll idx = 2;
    ll resp = 0;
    while(idx <= 9){
        if(digitos[idx] > 0){
            if(resp > INF/10) return INF;
            resp *= 10; 
            resp += idx;
            digitos[idx]--;
        }else{ 
            idx++;
        }
    }

    return resp;
}

int main(){
    _;
    ll t; cin >> t;
    map<ll, ll> mp;
    vector<p64> tempv(t+1);
    v64 vec(t+1);
    v64 resp(t+1, 0);
    tempv[t] = {INF, t};
    forn(i,0,t) cin >> tempv[i].first, tempv[i].second = i;
    sort(tempv.begin(), tempv.end());

    forn(i, 0, t+1) {
        mp[tempv[i].second] = i;
        vec[i] = tempv[i].first;
    }

    auto it_ = lower_bound(vec.begin(), vec.end(), 10);
    ll idx_ = it_ - vec.begin();
    resp[idx_]++;

    forn(a, 0, 3*MAXDIG+1)
    forn(b, 0, 2*MAXDIG+1)
    forn(c, 0, MAXDIG+1)
    forn(d, 0, MAXDIG+1){
        ll num = testa(a,b,c,d);
        debug(a);
        debug(b);
        debug(c);
        debug(d);
        debug(num);
        auto it = lower_bound(vec.begin(), vec.end(), num);
        ll idx = it - vec.begin();
        resp[idx]++;
    }

    forn(i, 1, t) {
        resp[i] += resp[i-1];
    }

    forn(i, 0, t){
        cout << resp[mp[i]] << ln;
    }
    return 0;
}