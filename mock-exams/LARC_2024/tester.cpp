#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

set<ll> open, closed;
ll n;
v64 v;

bool is_valid();
bool solve();
void subsets(v64 &arr);

bool is_valid(){
    ll pico = -1;
    forn(i,0,n){
        if(v[i] == n){
            pico = i;
        }
    }
    forn(i,0,pico){
        if(v[i] > v[i+1]){
            return false;
        }
    }
    forn(i,pico+1,n){
        if(v[i-1] < v[i]){
            return false;
        }
    }
    return true;
}

void permutations(v64 &arr) {
    do {
        v = arr;
        if(is_valid()){
            subsets(arr);
        }
    } while (next_permutation(arr.begin(), arr.end()));
}

void subsets(v64 &arr) {
    int n = arr.size();
    int total_subsets = 1 << n;
    

    for (int i = 0; i < total_subsets; ++i) {
        v = arr;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) { 
                v[j] = 0;
            }
        }
        v64 aux = v;

        // forn(i,0,n){
        //     cout << aux[i] << ' ';
        // }
        // cout << ln;
        // bool b = solve();    
        // forn(i,0,n){
        //     cout << v[i] << ' ';
        // }
        // cout << ln; 
        // cout << ln; 
        if(not solve()){
        forn(i,0,n){
            cout << aux[i] << ' ';
        }
        cout << ln;
    }
    }
    
}


void solve(ll l_current, ll r_current, set<ll>& open){
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
        for(auto x: open){
            v[l_current] = x;
            l_current++;
        }
    }else{
        for(auto x: open){
            v[r_current] = x;
            r_current--;
        }
    }
}

void l_pico(set<ll>& open){
    //cout << "lpico" << ln;
    forn(i,0,n){
        if(v[i] == 0){
            v[i] = *(--open.end());
            open.erase(--open.end());
        }
    }
}

void r_pico(set<ll>& open){
    //cout << "rpico" << ln;
    forn(i,0,n){
        if(v[i] == 0){  
            v[i] = *(open.begin());
            open.erase(open.begin());
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

bool solve(){
    open.clear();
    closed.clear();
    forn(i, 0, n) {
        if (v[i]) closed.insert(v[i]);
    }
    forn(i, 1, n + 1) {
        if (closed.find(i) == closed.end()) {
            open.insert(i);
        }
    }

    ll l_current = 0, l_bound = 0, r_current = n-1, r_bound = n-1;
    ll l_max = 0;
    ll r_max = 0;
    while (true) {
        if(v[l_current] == n){
            l_pico(open);
            break;
        }
        if(v[r_current] == n){
            r_pico(open);
            break;
        }
        if (r_current == l_current) {
            if (v[r_current] != 0) break;
            v[r_current] = *open.begin();
            break;
        }
        if (v[l_current] != 0) {
            l_max = max(v[l_current], l_max);
            l_current++;
            continue;
        }
        if (v[r_current] != 0) {
            r_max = max(v[r_current], r_max);
            r_current--;
            continue;
        }
        if (l_bound <= l_current) {
            l_bound = find_next(l_current);
        }
        if (r_bound >= r_current) {
            r_bound = find_previous(r_current);
        }
        if(l_bound > r_bound){
            solve(l_current, r_current, open);
            break;
        }
        ll guess = *open.begin();
        open.erase(guess);
        
        if (guess < l_max) {
            v[r_current] = guess;
            continue;
        } else if (guess < r_max) {
            v[l_current] = guess;
            continue;
        }
        
        if(l_bound == r_bound){
            if(l_bound - l_current < r_current - r_bound && guess > l_max){
               v[l_current] =   guess; 
            } else{
                v[r_current] = guess;
            }
            continue;
        }

        if (v[r_bound] < v[l_bound] && guess > r_max) {
            v[r_current] = guess;
        } else {
            v[l_current] = guess;
        }
    }
    /////////////////////////
    // forn(i, 0, n) {
    //     cout << v[i] << " ";
    // }

    return is_valid();
}

int main(){
    F_;
    cin >> n;
    v.resize(n);

    v64 arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1; // Preenche o array com números de 1 a n
    }
    permutations(arr);
    
    P_; return 0;
}