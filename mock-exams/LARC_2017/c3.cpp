#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())
#define dbg(x) cout << #x << " = " << x << ln


int main(){
    //fast_cin();
    ll k, n; cin >> k >> n;
    map<ll, ll> mapa;
    forn(i, n) {
        ll aux; cin >> aux;
        mapa[aux]++;
    }
    ll f, counter, a, b, counter2;
    counter = 0;
    counter2 = 0;
    if((n-1) % k == 0){
        f = (n-1)/k;
        for(auto p : mapa){
            if(p.se != f && p.se != f+1){
               cout << '*' << ln;
               return 0; 
            }
            if(p.se == f+1){
                a = p.fi;
                counter++;
            }
        }
        if(counter > 1){
            cout << '*' << ln;
            return 0;
        }
        cout << '-' << a << ln;
        return 0;
    }

    if((n+1) % k == 0){
        f = (n+1)/k;
        for(auto p : mapa){
            if(p.se != f && p.se != f-1){
               cout << '*' << ln;
               return 0; 
            }
            if(p.se == f-1){
                a = p.fi;
                counter++;
            }
        }
        if(counter > 1){
            cout << '*' << ln;
            return 0;
        }
        cout << '+' << a << ln;
    }

    if(n % k == 0){
        f = n/k;
        for(auto p : mapa){
            if(p.se != f && p.se != f+1 && p.se != f-1){
               cout << "b" << ln;
               return 0; 
            }
            if(p.se == f+1){
                a = p.fi;
                counter++;
            }
            if(p.se == f-1){
                b = p.fi;
                counter2++;
            }
        }
        if(counter > 1 || counter2 > 1){
            cout << "*" << ln;
            return 0;
        }
        cout << '-' << a << " +" << b << ln;
        return 0;
    }
}
