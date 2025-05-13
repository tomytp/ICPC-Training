#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _;
    string c; cin >> c;
    if(c[0] == '0'){
        cout << -1 << ln;
        return 0;
    }

    reverse(c.begin(), c.end());

    ll n = 0;
    
    forn(i, 0, c.size()) {
        n += (c[i] - '0')*(1ll<<i);
    }
    
    ll mask = (1ll<< (c.size()))-1;
 
    if(n == mask){
        cout << 0 << ln;
        return 0;
    }
    set<ll> current = {n};
    set<ll> next;
    forn(k, 0, 5) {
        for(auto val : current) {
            forn(i, 1, 40) {
                ll nx = val | (val >> i);
                debug(bitset<41>(nx));
                debug(k);
                if (nx == mask) {
                    cout << k+1 << ln;
                    return 0;
                }
                next.insert(nx);
            }
        }
        current.clear();
        swap(current, next);
    }
    cout << 6 << ln;
    return 0;
}