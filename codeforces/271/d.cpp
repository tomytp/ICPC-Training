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
ll k; string bin;

struct trie {
	vector<v64> to;
	v64 end, pref, valid_end;
	ll sigma; char norm;

	trie(ll sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {v64(sigma)};
		end = {0}, pref = {0}, valid_end = {0};
	}

	void insert(string s) {
		ll x = 0;
        ll ugly = 0;

		for (auto c : s) {
            if (bin[c-norm] == '0') ugly++;
            
			ll &nxt = to[x][c-norm];
			if (!nxt) {
				nxt = to.size();
				to.push_back(v64(sigma));
				end.push_back(0), pref.push_back(0); valid_end.push_back(ugly <= k);
			}
			x = nxt, pref[x]++;
		}
		end[x]++, pref[0]++;
	}

	ll find(string s) {
		ll x = 0;
		for (auto c : s) {
			x = to[x][c-norm];
			if (!x) return -1;
		}
		return x;
	}
};

int main(){
    _;
    string s; cin >> s;
    cin >> bin;
    cin >> k;
    
    trie t;
    do {
        t.insert(s);
        s.erase(s.begin());
    } while (s.size());

    ll ans = 0;
    for(auto& e : t.valid_end) if (e) ans++;
    cout << ans << ln;

    return 0;
}