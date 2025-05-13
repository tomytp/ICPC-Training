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

struct team {
    ll ac = 0, pd = 0, idx;

    bool operator < (const team l) const {
        assert(idx != l.idx);
        return idx < l.idx;
	}

};

ll read_str() {
    string s; cin >> s;
    cin >> s;
    
    ll ans = 0;
    for (auto c : s) {
        if (c == 'y') ans++;
    }

    
    assert(ans != 1);
    assert(ans != 2);
    if (ans <= 3) {
        return 0;
    }
    return ans - 3;
}
  
int main(){
    _;
    ll n, m, r; cin >> n >> m >> r;
    vector<team> v(n);

    ll tot_pending = 0;
    forn(i, 0, n) {
        string s; cin >> s;
        for (auto c: s) {
            if (c == 'A') v[i].ac++;
            if (c == 'P') v[i].pd++, tot_pending++;
            v[i].idx = i;
        }
    }
    
    ll curr = n-1;
    forn(i, 0, tot_pending) {
        while(v[curr].pd == 0) curr--;
        v[curr].pd--;
        ll jump = read_str();
        if (jump == 0) continue;

        ll temp = curr;
        forn(j, 0, jump) {
            swap(v[temp], v[temp-1]);
            temp--;
        }
    }

    forn(i, 0, n) {
        if (v[i].idx == r-1) {
            cout << i+1 << ln;
            return 0;
        }
    }
    

    return 0;
}