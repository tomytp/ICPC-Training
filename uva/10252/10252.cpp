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

string solve(string &a, string &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ca = 0, cb = 0, na = a.size(), nb = b.size();
    string ans = "";
    while (ca < na && cb < nb) {
        if (a[ca] == b[cb]) {
            ans.push_back(a[ca]);
            ca++; cb++;
            continue;
        }

        if (a[ca] < b[cb]) {
            ca++;
        } else {
            cb++;
        }
    }
    return ans;
}

int main(){
    _;
    vector<string> v;
    string aux;
    while (getline(cin, aux)) v.push_back(aux);
    ll n = v.size() / 2;
    forn(i, 0, n) {
        string &a = v[2*i], &b = v[2*i + 1];
        cout << solve(a, b) << ln;
    }
    return 0;
}