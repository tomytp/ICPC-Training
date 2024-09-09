#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln
#define dgb dbg

#define MAXSQRT 1100'100
#define MAXLOG 40
ll vec[MAXSQRT];

bool palin(ll b, ll n){
    ll pot = 1;
    ll aux = n;
    ll idx = 0;
    while(aux > 0){
        vec[idx] = aux%b;
        aux = aux/b;
        idx++;
    } 
    ll tam = idx;
    forn(i,0,tam){
        if(vec[i] != vec[tam-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    FAST_CIN;
    ll n; cin >> n;
    ll sqrtn = 0;
    while(sqrtn*sqrtn <= n-1){
        sqrtn++;
    }
    set<ll> resp;
    ll aux;

    if(n == 2){
        cout << "*" << ln;
        return 0;
    }

    resp.insert(n-1);

    forn(i,2,sqrtn){
        if(n%i == 0 && n!=(i)*(i+1)){
            resp.insert(n/i-1);
        }
        
        if(palin(i, n)){
            resp.insert(i);
        }
    }

    for(ll x: resp){
        cout << x << " ";
    }
    cout << ln;
}