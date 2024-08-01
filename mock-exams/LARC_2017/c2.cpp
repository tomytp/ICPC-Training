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
    
    vector<ll> vec;
    set<ll> s;
    for(auto p: mapa){
        ll counter = 0;
        for(auto q: mapa){
            s.insert(q.se);
            if(q.se == p.se){
                counter++;
            }
        }
        if(counter == 1){
            vec.pb(p.fi);
        }
        
    }

    vector<ll> vset(sz(s)+1);
    ll counter2 =0;
    for(auto x: s){
        vset[counter2] = x;
        counter2++; 
    }
    if(sz(s) > 3){
        cout << '*' << ln;
        return 0;
    }
    if(sz(s) == 2){
        ll a = *s.begin();
        ll b = *(++s.begin());
        if(b-a > 2){
            cout << '*' << ln;
        }
        if(b == a + 2){
            if(k == 2){
                cout << '-' << b << ' +' << a << ln;    
            }else{
                cout << '*' << ln;
            }
        }

        ll cont_a = 0;
        ll cont_b = 0;
        for(auto p: mapa){
            if(p.se == a){
                cont_a++;
            }
            if(p.se == b){
                cont_b++;
            }
        }
    }

    if(vset[2] - vset[0] > 2){
        cout << '*' << ln;
        return 0;
    }

    if(sz(vec) == 1){
        ll a = vec[0];
        bool menor = true;
        for(auto p: mapa){
            if(p.se < mapa[a]){

                menor = false;
            }
        }
        if(menor){
            cout << '+' << a << ln;
            return 0;
        }else{
            cout << '-' << a << ln;
            return 0;
        }
    } 

    if(sz(vec) == 2){
        ll a = vec[0];
        ll b = vec[1];
        bool menor = true;
        for(auto p: mapa){
            if(p.se < mapa[a]){
                menor = false;
            }
        }
        if(menor){
            cout << '-' << b << ' ' << '+' << a << ln;
            return 0;
        }else{
            cout << '-' << a << ' ' << '+' << b << ln;
            return 0;
        }
    }

    if(sz(vec) == 3){
        ll a = vec[0];
        ll b = vec[1];
        ll c = vec[2];
        ll maior, menor;
        if(mapa[a] > max(mapa[b],mapa[c])){
            maior = a;
        }
        if(mapa[b] > max(mapa[a],mapa[c])){
            maior = b;
        }
        if(mapa[c] > max(mapa[b],mapa[a])){
            maior = c;
        }

        if(mapa[a] < min(mapa[b],mapa[c])){
            menor = a;
        }
        if(mapa[b] < min(mapa[a],mapa[c])){
            menor = b;
        }
        if(mapa[c] < min(mapa[b],mapa[a])){
            menor = c;
        }

        cout << '-' << maior << ' ' << '+' << menor << ln   ;
        return 0;
    }
    return 0;
}
