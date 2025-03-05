#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll cash;
string chars = "BSC";

bool can_make(map<char, ll>& needed, map<char, ll>& storage, map<char, ll>& price, ll qtd) {
    ll cost = 0;
    for (auto c : chars) {
        ll missing = (needed[c] * qtd) - storage[c];
        if (missing <= 0) continue;

        cost += missing * price[c];
        if (cost > cash) return false;
    }
    return cost <= cash;
}

int main(){
    _;
    string s; cin >> s;
    map<char, ll> needed, storage, price;
    cin >> storage['B'] >> storage['S'] >> storage['C'];  
    cin >> price['B'] >> price['S'] >> price['C'];
    cin >> cash;

    forn(i, 0, s.size()) {
        needed[s[i]]++;
    }

    ll l = 0, r = 1000000000000000, ans = 0;
    while (l <= r) {
        ll mid = l + (r-l) / 2;
        if (can_make(needed, storage, price, mid)) {
            ans = mid;
            l = mid+ 1 ;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << ln;
    return 0;
}