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

void solve(ll a, ll b, ll c){
    forn(i,0,a){
        cout << "-X-";
    }
    forn(i,0,b){
        cout << "X-";
    }
    if(c==1){
        cout << "X";
    }
    cout << ln;
    return;
}
int main(){
    F_;
    ll n, k, a, b, c; cin >> k >> n;
    if(3*k-n<0 || n-2*k<-1) {
        cout << '*' << ln;
        return 0;
    }
    if(n==2*k-1){
        solve(0, k-1, 1);
        return 0;
    }
    solve(n-2*k,3*k-n,0);
    P_;return 0;
}