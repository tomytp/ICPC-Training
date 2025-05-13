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

void solve() {
    string s1, s2; cin >> s1 >> s2;

    ll b1 = 0, b2 = 0;
    for (auto& c : s1) if (c == 'B') b1++;
    for (auto& c : s2) if (c == 'B') b2++;

    if (abs(b1 - b2) & 1) {
        cout << "NO\n";
        return;
    }

    string s3 = "", s4 = "";
    for (auto& c : s1) if (c != 'B') s3.push_back(c);
    for (auto& c : s2) if (c != 'B') s4.push_back(c);

    swap(s1, s3);
    swap(s2, s4);

    bool swaped = true;
    while(swaped) {
        swaped = false;

        if (!s1.size()) break;
        forn(i, 0, s1.size() - 1) {
            if (s1[i] == s1[i+1]) {
                s1.erase(s1.begin() + i);
                s1.erase(s1.begin() + i);
                swaped = true;
                break;
            }
        }
    }

    swaped = true;
    while(swaped) {
        swaped = false;

        if (!s2.size()) break;
        forn(i, 0, s2.size() - 1) {
            if (s2[i] == s2[i+1]) {
                s2.erase(s2.begin() + i);
                s2.erase(s2.begin() + i);
                swaped = true;
                break;
            }
        }
    }

    debug(s1);
    debug(s2);
    if (s1 == s2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}