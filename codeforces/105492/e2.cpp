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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

v64 vec;

void prep(ll n){
    vec.resize(n+1);
    forn(i,0,n+1) vec[i] = uniform(-20,20);
    sort(vec.begin(), vec.end());
    // vec = {1,1,9,20,26,28,29,41,55,70,72};
}

ll burro(){
    ll n = vec.size()-1;
    debug(target);
    
    ll g2 = 2;
    double max_v = 0;
    forn(i,2,n){
        if (max_v < sqrt(abs(vec[1]- vec[n])) + sqrt(abs(vec[i]- vec[n])) + sqrt(abs(vec[1]- vec[i]))) {
            g2 = i;
            max_v = sqrt(abs(vec[1]- vec[n])) + sqrt(abs(vec[i]- vec[n])) + sqrt(abs(vec[1]- vec[i]));
        }
    }

    return g2;
}

ll interact(ll idx){
    // cout << "? " << idx << ln;
    // cout.flush();
    // ll resp;
    // cin >> resp;
    return vec[idx];
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
    ll n; //cin >> n;
    n = 10;
    ll counter = 1;
    while(counter){
        cout << counter << ln;
        counter++;
        prep(n);
        ll g1, g3;
        
        g1 = interact(1);
        g3 = interact(n);
        
        ll target = (g1+g3)/2;
        
        p64 x1 = bs(target, n);
        if (x1.first == 0) x1.first =2, x1.second = INF;
        p64 x2 = bs1(target, n);
        if (x2.first == 0) x2.first =2, x2.second = INF;
        ll resp;
        if(g1 + g3 < x1.second + x2.second){
            resp = x1.first;
            // cout << "! 1 " << x1.first << " " << n << ln;
        } else {
            resp = x2.first;
            // cout << "! 1 " << x2.first << " " << n << ln;
        }
        
        ll resp_burro = burro();
        
        if(abs(2*vec[resp]-vec[1]-vec[n]) != abs(2*vec[resp_burro]-vec[1]-vec[n])){
            forn(i,1,n+1) cout << vec[i] << " \n"[i==n];
            cout << resp << ln;
            cout << resp_burro << ln;
            break;
        }
    }

    return 0;
}