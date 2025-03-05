#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _; ll t, d, m; cin >> t >> d >> m;
    v64 minute(m+2);
    minute[0] = 0;
    forn(i, 0, m) cin >> minute[i+1];
    minute[m+1] = d;

    sort(minute.begin(), minute.end());

    bool win = false;
    forn(i, 0, m+1){
        if(minute[i+1] - minute[i] >= t) win = true;
    }

    if(win){
        cout << "Y" << ln;
    }
    else {
        cout << "N" << ln;
    }
    return 0;
}