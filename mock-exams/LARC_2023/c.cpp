#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef pair<ll,ll> p64;
typedef pair<p64,p64> pp64; 

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln
#define dgb dbg
#define fi first
#define se second

v64 vec;

ll rustica(ll n, ll l, ll k){
    ll lk = k*l;    
    v64 freq_marca(lk+1,0);
    v64 freq_freq(lk+1,0);
 

    forn(i,0,lk){
        freq_marca[vec[i]]++;
    }
    forn(i,0,lk){
        freq_freq[freq_marca[i]]++;
    }
    if(freq_freq[freq_marca[0]] == k){
        return lk;  
    }
    forn(i,1,n-lk+1){
        freq_freq[freq_marca[vec[i-1]]]--;
        freq_marca[vec[i-1]]--;
        freq_freq[freq_marca[vec[i-1]]]++;

        freq_freq[freq_marca[vec[i+lk-1]]]--;
        freq_marca[vec[i+lk-1]]++;
        freq_freq[freq_marca[vec[i+lk-1]]]++;

        if(freq_freq[freq_marca[vec[i+lk-1]]] == k){
            return lk;    
        }
    }
    return 0;
}

void solve_burro(ll n, ll k) {
    ll l = n/k;
    for (; l >= 1; l--) {
        ll p = rustica(n, l, k);
        if (p) {
            cout << p << ln;
            return;
        }
    }
    cout << 0 << ln;
}

void solve_smart(ll n, ll k) {
    v64 tab(k, 0);
    map<v64, set<ll>> mp;

    forn(i, 0, n) {
        tab[vec[i]]++;

        if (tab[vec[i]] == 1) {
            ll menor = LLONG_MAX;

            forn(j, 0, k) {
                if (tab[j] == 0) {
                    menor = LLONG_MAX;
                    break;
                }
                if (tab[j] < menor) menor = tab[j];              
            }
            if (menor != LLONG_MAX) {
                forn(j, 0, k) {
                    tab[j] -= menor;
                }
            }
        }
        mp[tab].insert(i);
    }

    ll diff = 0;
    for (auto kv  : mp) {
        if (*(kv.second.rbegin()) - *(kv.second.begin()) > diff) diff = *(kv.second.rbegin()) - *(kv.second.begin());
    }
    cout << diff << ln;
}

int main() {
    FAST_CIN;
    ll n; cin >> n;
    ll k; cin >> k;
    vec.resize(n);
    forn(i, 0, n) {
        cin >> vec[i];
        vec[i]--;
    }
    ll raiz = sqrt(n);
    // ll raiz = LLONG_MAX;
    if (k > raiz) {
        solve_burro(n, k);
    } else {
        solve_smart(n, k);
    }
       
}