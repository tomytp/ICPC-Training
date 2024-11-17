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
    ll n; cin >> n;
    ll aux, previous;
    bool up = true;
    ll count = 0;
    ll start = -1, end = -1;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    previous = v[0];
    forn(i, 1, n) {
        aux = v[i];
        if (up) {
            if (aux < previous) {
                up = false;
                count++;
                start = i - 1;
            }
        } else {
            if (aux > previous) {
                up = true;
                end = i - 1;
            }
        }
        previous = aux;
    }
    if (count == 0) {
        cout << "yes\n1 1\n";
        return 0;
    }
    dbg(end);
    if (count <= 1) {
        if (start != -1 && end == -1) {
            end = n-1;
        }
    } else {
        cout << "no\n";
        return 0;
    }
    dbg(end);
    if (start > 0 && v[end] < v[start-1]) {
        cout << "no\n";
        return 0;
    }
    dbg(end);
    if (end < n-1 && v[start] > v[end+1]) {
        cout << "no\n";
        return 0;
    }

    cout << "yes\n" << start+1 << " " << end+1 << ln;
    P_; return 0;
} 