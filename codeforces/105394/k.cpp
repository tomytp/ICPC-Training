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

map<char, char> vert = {
    {'b', 'p'},
    {'p', 'b'},
    {'d', 'q'},
    {'q', 'd'},
};

map<char, char> horiz = {
    {'b', 'd'},
    {'d', 'b'},
    {'p', 'q'},
    {'q', 'p'},
};

int main(){
    _;
    string a, b; cin >> a >> b;
    ll h = 0, v = 0;
    for(auto c : b) {
        if (c == 'h') h++;
        else if (c == 'v') v++;
        else {
            h++; v++;
        }
    }

    h %= 2;
    v %= 2;
    if (v) {
        for (auto & c : a) {
            c = vert[c];
        }
    }

    if (h) {
        reverse(a.begin(), a.end());
        for (auto& c : a) {
            c = horiz[c];
        }
    }

    cout << a << ln;

    
    return 0;
}