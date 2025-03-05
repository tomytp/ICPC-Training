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

bool hasDigitSeven(ll number) {
    number = abs(number);
    
    while (number > 0) {
        if (number % 10 == 7) {
            return true;
        }
        number /= 10;
    }
    return false;
}

void solve() {
    ll n; cin >> n;
    

    if (hasDigitSeven(n)) {
        cout << 0 << ln;
        return;
    }

    v64 v = {n}, nx;

    ll st = 9;
    while (st < n*10) {
        ll calc = n + st;
        if (hasDigitSeven(calc)) {
            cout << 1 << ln;
            return;
        }
        nx.push_back(calc);
        st *= 10;
        st += 9;
    }
    ll it = 1;
    while (true) {
        it++;
        ll st = 9;
        for (auto& x : nx) {
            x += st;
            if (hasDigitSeven(x)) {
                cout << it << ln;
                return;
            }

            st *= 10;
            st += 9;
        }
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}