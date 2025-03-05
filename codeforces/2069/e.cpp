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

string s;
int a, b, ab, ba;
vector<vector<vector<vector<vector<bool>>>>> dp;

bool rec(int pos, int ca, int cb, int cab, int cba) {
    if (pos == s.length()) return true;
    if (pos > s.length()) return false;
    if (ca > a || cb > b || cab > ab || cba > ba) return false;
    if (dp[pos][ca][cb][cab][cba]) return false;
    
    dp[pos][ca][cb][cab][cba] = true;
    
    // Try pairs first
    if (pos + 1 < s.length()) {
        if (s[pos] == 'A' && s[pos + 1] == 'B' && cab < ab) {
            if (rec(pos + 2, ca, cb, cab + 1, cba)) return true;
        }
        if (s[pos] == 'B' && s[pos + 1] == 'A' && cba < ba) {
            if (rec(pos + 2, ca, cb, cab, cba + 1)) return true;
        }
    }
    
    // Try single character
    if (s[pos] == 'A' && ca < a) {
        if (rec(pos + 1, ca + 1, cb, cab, cba)) return true;
    }
    if (s[pos] == 'B' && cb < b) {
        if (rec(pos + 1, ca, cb + 1, cab, cba)) return true;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> s >> a >> b >> ab >> ba;
        dp.assign(s.length() + 1, 
            vector<vector<vector<vector<bool>>>>(a + 1, 
                vector<vector<vector<bool>>>(b + 1,
                    vector<vector<bool>>(ab + 1,
                        vector<bool>(ba + 1, false)))));
        cout << (rec(0, 0, 0, 0, 0) ? "YES" : "NO") << ln;
    }
    return 0;
}