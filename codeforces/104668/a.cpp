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

// Aho-corasick 
//
// query retorna o somatorio do numero de matches de
// todas as stringuinhas na stringona
//
// insert - O(|s| log(SIGMA))
// build - O(N), onde N = somatorio dos tamanhos das strings
// query - O(|s|)

namespace aho {
    const ll MAX = 100000000;

	map<char, ll> to[MAX];
	ll link[MAX], idx, term[MAX], exit[MAX], sobe[MAX], max_match[MAX];

	void insert(string& s) {
		ll at = 0;
		for (char c : s) {
			auto it = to[at].find(c);
			if (it == to[at].end()) at = to[at][c] = ++idx;
			else at = it->second;
		}
		term[at]++, sobe[at]++;
        max_match[at] = s.size();
	}
	void build() {
		queue<ll> q;
		q.push(0);
		link[0] = exit[0] = -1;
		while (q.size()) {
			ll i = q.front(); q.pop();
			for (auto [c, j] : to[i]) {
				ll l = link[i];
				while (l != -1 and !to[l].count(c)) l = link[l];
				link[j] = l == -1 ? 0 : to[l][c];
				exit[j] = term[link[j]] ? link[j] : exit[link[j]];
				if (exit[j]+1) sobe[j] += sobe[exit[j]];
				q.push(j);
			}
		}
	}
	ll query(string& s) {
		ll at = 0, ans = 0;
		for (char c : s){
			while (at != -1 and !to[at].count(c)) at = link[at];
			at = at == -1 ? 0 : to[at][c];
		}
		return max_match[ans];
	}
}

int main(){
    _; ll n; cin >> n;
    string mens; cin >> mens;
    vector<string> word(n);
    forn(i, 0, n){
        cin >> word[i];
        aho::insert(word[i]);
    }

    aho::build();
    forn(i, 0, n){
        string aux = mens.substr(0, i+1);
        cout << aho::query(aux);
    }

    return 0;
}