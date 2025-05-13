#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll ask(char c, ll i, ll j, ll k){
    cout << c << ' ' << i << ' ' << j << ' ' << k << ln;
    cout.flush();
    if(c == '!') return 0;
    ll resp;
    cin >> resp;
    return resp;
}

void solve(){
    ll n; cin >> n;
    ll a, b, c, x;

    a = uniform(1,n);
    b = a;
    c = a;

    while(b == a) b = uniform(1,n);
    while((c == a) || (c == b)) c = uniform(1,n);
    
    x = ask('?', a, b, c);

    if(x == 0){
        ask('!', a, b, c);
        return;
    }

    forn(h,0,75){
        ll ansa, ansb, ansc;
        
        ansa = ask('?', x, b, c);
        ansb = ask('?', a, x, c);
        ansc = ask('?', a, b, x); 

        if(ansa == 0){
            ask('!', x, b, c);
            return;
        }
        if(ansb == 0){
            ask('!', a, x, c);
            return;
        }
        if(ansc == 0){
            ask('!', a, b, x);
            return;
        }

        ll choice = uniform(0,2); 
        
        if(choice == 0){
            a = x;
            x = ansa;
        }
        if(choice == 1){
            b = x;
            x = ansb;
        }
        if(choice == 2){
            c = x;
            x = ansc;
        }
    }   
    assert(false);
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}