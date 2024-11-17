#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(NULL)
#define P_ if(D_)cout<<"DEBUG\n"
#define dbg(x) if(D_) cout << #x << " = " << x << ln

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define dgb dbg

void solve() {

	ll n;
	cin >> n;

	v64 v(n + 1);

	forn(i, 1, n + 1) {
		cin >> v[i];
	}

	v64 receives(n + 1, 0);
	v64 gives(n + 1, -1);
	ll tot = 0;

	forn(i, 1, n + 1) {

		if (!receives[v[i]]) {
			gives[i] = v[i];
			receives[v[i]] = i;
			++tot;
		}
	}

	cout << tot << ln;

	v64 todo;

	forn(i, 1, n + 1) {
		if (receives[i] == 0)
			todo.push_back(i);
	}

	forn(i, 1, n + 1) {
		if (gives[i] == -1) {

			if (todo.back() == i) {
				swap(todo.back(), todo[0]);
			}

			if (todo.back() == i) {
				ll j = receives[v[i]];
				gives[j] = i;
				gives[i] = v[i];
				todo.pop_back();
			}
			else {
				gives[i] = todo.back();
				todo.pop_back();
				receives[gives[i]] = i;
			}
		}
	}

	forn(i, 1, n + 1) {
		cout << gives[i] << " \n"[i==n];
	}
}

int main() {
    F_;
    ll t; 
    cin >> t;
    while(t--) solve();
    return 0;
}