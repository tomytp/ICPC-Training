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

#define NMAX 300

bool solve(ll r, ll c, vector<bitset<NMAX>>& matrix, bitset<NMAX>& bt){
    vector<vector<bool>> bmatrix(r, vector<bool>(c, false));
    forn(j, c) {
        forn (i, r) {
            bmatrix[i][j] = (bt & matrix[i]) == 0;
        }
        bool aux = bt[0];
        bt = bt >> 1;
        bt[c-1] = aux;
    }
    set<p64> closedset;
    set<p64> openset;
    forn(j, c) {
        if (bmatrix[0][j]) {
            openset.insert(mp(0, j));
        }
    }
    
    ll ivar[] = {0, 0, 1, -1};
    ll jvar[] = {1, -1, 0, 0};

    while (sz(openset) > 0) {
        auto it = openset.begin();
        p64 p = *it;
        if (p.fi == r-1 && bmatrix[p.fi][p.se]) {
            return true;
        }
        openset.erase(it);
        closedset.insert(p);
        forn(adj, 4) {
            ll i = (p.fi + ivar[adj]);
            ll j = (p.se + jvar[adj] + c) % c;
            if (i < 0 || i >= r) continue;
            if (i == r-1 && bmatrix[i][j]) {
                return true;
            }
            if (bmatrix[i][j] && closedset.find(mp(i,j)) == closedset.end()) {
                openset.insert(mp(i,j));
            }
        }
    }
    return false;
}

int main(void){
    // fast_cin();
    ll r, c; cin >> r >> c;
    string aux;
    cin >> aux;
    bitset<NMAX> bt(aux);
    bitset<NMAX> bt2;
    vector<bitset<NMAX>> matrix(r);
    forn(i, r) {
        cin >> aux;
        bitset<NMAX> auxbt(aux);
        matrix[i] = auxbt;
    }
    forn(i, c) {
        bt2[i] = bt[c-i-1];
    }

    bool res = solve(r, c , matrix, bt) || solve(r, c, matrix, bt2);

    cout << "NY"[(int) res] << ln;    
}