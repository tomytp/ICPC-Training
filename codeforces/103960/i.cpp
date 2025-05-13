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
    v64 v(8);
    forn(i, 0, 8) {
        cin >> v[i];
    }

    forn(i, 0, 8) {
        if (v[i] != 1 && v[i] != 0) {
            cout << "F" << ln;
            return 0;
        }
    }
    cout << "S" << ln;
    return 0;
}