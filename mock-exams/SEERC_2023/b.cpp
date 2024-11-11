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

#define NMAX 200'010
unordered_map<ll, set<ll>> contra_vec;
v64 perm(NMAX);
v64 v(NMAX);

bool make_perm(ll soma, ll n){
    forn(i,0,n){
        ll search = soma-v[i];
        if((ll)contra_vec[search].size() == 0) return false;
        perm[i] = *contra_vec[search].begin();
        contra_vec[search].erase(perm[i]);
    }
    return true;
}

int main(){
    F_;
    ll n;
    cin >> n;
    ll maximo = 0, minimo = 2'000'000'000;

    forn(i,0,n){
        cin >> v[i];
        minimo = min(v[i], minimo);
        maximo = max(v[i], maximo);
        contra_vec[v[i]].insert(i);
    }
    ll sum = maximo + minimo;
    
    if(make_perm(sum, n)){
        forn(i,0,n){
            cout << perm[i]+1 << " ";
        }
        cout << ln;
    } else {
        cout << "-1\n";
    }

    P_; return 0;
}