#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define P_ if(D_)cout<<"DEBUG\n"
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define dbg(x) if(D_) cout << #x << " = " << "\n";

#define ln '\n'
#define dgb dbg

v64 v;
ll n;
set<ll> open, closed;

void trocado(ll l_current, ll r_current, ll max_l, ll max_r){
    if(l_current == 0){
        for(auto x: open){
            v[l_current] = x;
            l_current++;
        } 
        return;
    }
    if(r_current == n-1){
        for(auto x: open){
            v[r_current] = x;
            r_current--;
        } 
        return;
    }

    ll val_l_bound = v[l_current-1];
    ll val_r_bound = v[r_current+1];

    if(val_l_bound < val_r_bound){
        vector<ll> menores;
        for(auto x: open){
            if (x < max_l) {
                menores.push_back(x);
                continue;
            } 
            v[l_current] = x;
            l_current++;
        }
        for(ll i = menores.size() - 1; i >= 0; i--) {
            v[l_current] = menores[i];
            l_current++;
        }
    }else{
        vector<ll> menores;
        for(auto x: open){
            if (x < max_r) {
                menores.push_back(x);
                continue;
            } 
            v[r_current] = x;
            r_current--;
        }
        for(ll i = menores.size() - 1; i >= 0; i--) {
            v[r_current] = menores[i];
            r_current--;
        }
    }
}

ll find_next(ll i) {
    forn(j, i, n) {
        if (v[j] != 0) return j;
    }
    return n;
} 

ll find_previous(ll i) {
    for (ll j = i; j >= 0; j--) {
        if (v[j] != 0) return j;
    }
    return -1;
}

void pico_l() {
    forn(i, 0, n) {
        if (v[i] == 0) {
            v[i] = *(--open.end());
            open.erase(--open.end());
        }
    }
}

void pico_r() {
    forn(i, 0, n) {
        if (v[i] == 0) {
            v[i] = *(open.begin());
            open.erase(open.begin());
        }
    }
}


int main() {
    F_;
    cin >> n;
    v.resize(n); 
    forn(i, 0, n) {
        cin >> v[i];
        if (v[i]) closed.insert(v[i]);
    }
    forn(i, 1, n + 1) {
        if (closed.find(i) == closed.end()) {
            open.insert(i);
        }
    }


    ll l = 0, r = n-1;
    ll max_l = 0, max_r = 0;
    ll l_bound = find_next(l);
    ll r_bound = find_previous(r);
    while (l != r) {
        if (v[l] == n) {
            pico_l();
            break;
        }
        if (v[r] == n) {
            pico_r();
            break;
        }
        
        if (v[l] != 0) {
            max_l = v[l];
            l++;
            continue;
        }
        if (v[r] != 0) {
            max_r = v[r];
            r--;
            continue;
        }

        if (l > l_bound) {
            l_bound = find_next(l);
        }
        if (r < r_bound) {
            r_bound = find_previous(r);
        }

        if (l_bound > r_bound) {
            trocado(l,r, max_l, max_r);
            break;
        }

        ll guess = *open.begin();
        open.erase(open.begin());

        if (l_bound != r_bound) {
            if (guess < max_l) {
                v[r] = guess;
                continue;
            }
            if (guess < max_r) {
                v[l] = guess;
                continue;
            }
            if (v[l_bound] > v[r_bound]) {
                v[r] = guess;
            } else {
                v[l] = guess;
            }
            continue;
        } else {
            if (guess < max_l) {
                v[r] = guess;
                continue;
            }
            if (guess < max_r) {
                v[l] = guess;
                continue;
            }
            if(abs(l_bound - l) < abs(r_bound - r)){
                v[l] = guess;
            }else {
                v[r] = guess;
            }
        }
    }

    ll pico = -1;
    forn(i,0,n){
        if(v[i] == n){
            pico = i;
        }
    }
    forn(i,0,pico){
        if(v[i] > v[i+1]){
            cout << '*' << ln;
            return 0;
        }
    }
    forn(i,pico+1,n){
        if(v[i-1] < v[i]){
            cout << '*' << ln;
            return 0;
        }
    }
    forn(i, 0, n) {
        cout << v[i] << " ";
    }

    cout << ln;
    P_;return 0;
}

