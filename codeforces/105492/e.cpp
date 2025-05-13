#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

typedef long double ld;

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

ll qers = 0;

ll interact(ll idx){
    assert(qers <= 50);
    qers++;
    cout << "? " << idx << ln;
    cout.flush();
    ll resp;
    cin >> resp;
    return resp;
}

p64 bs(ll target, ll n) {
    ll l = 2;
    ll r = n-1;
    p64 resp = {0, 0};

    while(l <= r){
        ll mid = (l+r)/2;
        ll curr = interact(mid);

        if(curr <= target) {
            resp = {mid, curr};
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return resp;
}

p64 bs1(ll target, ll n) {
    ll l = 2;
    ll r = n-1;
    p64 resp = {0, 0};

    while(l <= r){
        ll mid = (l+r)/2;
        ll curr = interact(mid);

        if(curr > target) {
            resp = {mid, curr};
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return resp;
}


int main(){
    ll n; cin >> n;

    ll g1, g3;

    g1 = interact(1);
    g3 = interact(n);

    ll target = (g1+g3)/2;

    p64 x1 = bs(target, n);
    if (x1.first == 0) x1.first =2, x1.second = INF;
    p64 x2 = bs1(target, n);
    if (x2.first == 0) x2.first =2, x2.second = INF;


    debug(x1.first);
    debug(x1.second);
    debug(x2.first);
    debug(x2.second);
    
    if(x2.first == 0 || g1 + g3 < x1.second + x2.second){
        cout << "! 1 " << x1.first << " " << n << ln;
    } else {
        cout << "! 1 " << x2.first << " " << n << ln;
    }

    return 0;
}