#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;
using vp64 = vector<p64>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << x << ln
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define mp make_pair

int main() {
    FAST_CIN;
    ll p, aux, counter =0; cin >> p;
    v64 solve(p,0);
    solve[1]=p-1;
    forn(a,2,p){
        aux = a;
        counter=1;
        while(aux !=1){
            aux = (aux*a)%p;
            counter++;
        }
        aux = a;
        forn(j, 1, counter+1){
            solve[aux]+=(p-1)/counter;
            aux = (aux*a)%p;
        }
    }

    forn(i, 1, p){
        cout << solve[i] << " ";
    }
    cout << ln;
}
