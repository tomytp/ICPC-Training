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
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())

#define NMAX 300

struct possiv {
    ll position;
    bitset<NMAX> cavalos;
};


int main(){
    // fast_cin();
    ll n; cin >> n;

    vector<string> cavalos(n);
    unordered_map<string, int> ind_by_horse(500);
    forn(i, n) {
        cin >> cavalos[i];
        ind_by_horse[cavalos[i]] = i;
    }

    ll corridas; cin >> corridas;
    bitset<NMAX> aux;
    forsn(i, n, NMAX) {
        aux[i] = true;
    }
    vector<bitset<NMAX>> matrix(n, aux);

    forn(corrida, corridas) {
        ll qt, winner; cin >> qt >> winner;
        winner--;
        bitset<NMAX> race;
        forn(i, qt) {
            string c; cin >> c;
            race[ind_by_horse[c]] = true;
        }
        
        forn(i, winner) {
            matrix[i] = matrix[i] | race;
        }
        matrix[winner] = race.flip() | matrix[winner];
    }


    vector<string> order(n);
    forn(i, n) {
        ll j = 0;
        for (; j<n; j++) {
            if (!matrix[i][j]) break;
        }
        forsn(k, i, n) {
            matrix[k][j] = true;
        }
        order[i] = cavalos[j];
    }

    for (string h : order) {
        cout << h << " ";
    }
    cout << ln;
}