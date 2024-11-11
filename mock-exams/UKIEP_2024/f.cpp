#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define dgb dbg
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

#define NMAX 10005
vv64 dist(NMAX,v64(NMAX,-1));
vv64 emb(NMAX,v64(102));
ll n, k, l;

void calc(ll i){
    ll d = 0;
    forn(j,0,n){
        d = 0;
        forn(t,0,l){
            d += abs(emb[i][t] - emb[j][t]);
        }
        dist[i][j] = d;
        dist[j][i] = d;
    }
    return;
}

int main() {
    fast_cin();
    cin >> n >> l >> k;
    vector<string> nome(n);

    forn(i,0,n){
        cin >> nome[i];
        forn(j,0,l){
            cin >> emb[i][j];
        }
    }


    v64 resp;
    ll best_n, best_val; 
    best_val = 0;
    ll aux;
    calc(0);
    forn(i,1,n){
        if(dist[0][i] > best_val){
            best_val = dist[0][i];
            best_n = i;
        }
    }
    resp.push_back(best_n);
    calc(best_n);
    forn(i,1,k){
        best_val = 0;
        forn(j,0,n){
            aux = 1'000'000;
            for(ll x:resp){
                aux = min(aux, dist[j][x]);
            }
            if(aux > best_val){
                best_val = aux;
                best_n = j;
            }
        }
        resp.push_back(best_n);
        calc(best_n);
    }

    for(ll x: resp){
        cout << nome[x] << ln;
    }
    return 0;
}