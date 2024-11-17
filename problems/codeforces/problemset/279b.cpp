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

int main(){
    F_;
    ll n, t; cin >> n >> t;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    ll l = 0, r = 0, sum = 0, books = 0, max_books = 0;
    while (r < n) {
        if (sum + v[r] <= t) {
            sum += v[r];
            books++;
            max_books = max(books, max_books);
            r++;
        } else {
            sum -= v[l];
            books--;
            l++;
        }
    }
    
    cout << max_books << ln;
    P_; return 0;
}