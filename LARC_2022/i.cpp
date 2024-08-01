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

set<pair<ll, p64>> inteligentes;
vv64 matrix;
ll maior = 0;
ll ivar[] = {0, 0, 1, -1};
ll jvar[] = {1, -1, 0, 0};
ll r, c;

void solve() {
    set<pair<ll, p64>> openSet;
    set<p64> closedSet;
    auto ipar = inteligentes.begin();
    p64 par = (*ipar).second;
    inteligentes.erase(ipar);
    openSet.insert(mp(matrix[par.fi][par.se], par));

    ll contador = 0;
    while(sz(openSet) > 0) {
        auto ip = openSet.begin();
        auto p = *(ip);
        openSet.erase(ip);
        ll val = p.fi;
        auto ij = p.se;
        closedSet.insert(ij);
        contador++;
        
        forn (adj, 4) {
            ll i = ij.fi + ivar[adj];
            ll j = ij.se + jvar[adj];
            if (i >= 0 && j >=0 && i < r && j < c && closedSet.find(mp(i,j)) == closedSet.end() && matrix[i][j] > val) {
                openSet.insert(mp(matrix[i][j], mp(i, j)));
                inteligentes.erase(mp(matrix[i][j], mp(i, j)));
            }
        }
    }
    if (contador > maior) {
        maior = contador;
    }
}

int main(){
    fast_cin();
    cin >> r >> c;
    matrix.resize(r, v64(c));
    forn(i, r) {
        forn(j, c) {
            cin >> matrix[i][j];
            inteligentes.insert(mp(matrix[i][j], mp(i, j)));
        }
    }
    while (sz(inteligentes)  > 0) {
        solve();
    }
    cout << maior << ln;
    return 0; 
}