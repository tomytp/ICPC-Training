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
ll a, b, c, ab, bc, ac, abc;
ll k;

struct dinitz {
	const bool scaling = true;
	ll lim;
	struct edge {
		ll to, cap, rev, flow;
		bool res;
		edge(ll to_, ll cap_, ll rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<ll> lev, beg;
	ll F;
	dinitz(ll n) : g(n), F(0) {}

	void add(ll _a, ll _b, ll _c) {
		g[_a].emplace_back(_b, _c, g[_b].size(), false);
		g[_b].emplace_back(_a, 0, g[_a].size()-1, true);
	}

	bool bfs(ll s, ll t) {
		lev = vector<ll>(g.size(), -1); lev[s] = 0;
		beg = vector<ll>(g.size(), 0);
		queue<ll> q; q.push(s);
		while (q.size()) {
			ll u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}

	ll dfs(ll v, ll s, ll f = INF) {
		if (!f or v == s) return f;
		for (ll& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			ll foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}

	ll max_flow(ll s, ll t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (ll ff = dfs(s, t)) F += ff;
		return F;
	}

	void reset() {
		F = 0;
		for (auto& edges : g) for (auto& e : edges) e.flow = 0; 
	}
};

ll adjust(ll v, ll c_, ll k_, ll &offset) {
    if (v <= c_ * k_) return v;
    offset += (v - ((v%k_) + (c_-1)*(k_)))/k_;
    return (v%k_) + (c_-1)*(k_);
}

bool testa_fluxo(ll A, ll B, ll C){
    dinitz fluxo(13);

    if(a != 0) fluxo.add(0, 1, a);
    if(b != 0) fluxo.add(0, 2, b);
    if(c != 0) fluxo.add(0, 3, c);
    if(ab != 0) fluxo.add(0, 4, ab);
    if(bc != 0) fluxo.add(0, 5, bc);
    if(ac != 0) fluxo.add(0, 6, ac);
    if(abc != 0) fluxo.add(0, 7, abc);

    if(A != 0){
        fluxo.add(1, 8, INF);
        fluxo.add(4, 8, INF);
        fluxo.add(6, 8, INF);
        fluxo.add(7, 8, INF);
        fluxo.add(8,11, A*k);
    }
    if(B != 0){
        fluxo.add(2, 9, INF);
        fluxo.add(4, 9, INF);
        fluxo.add(5, 9, INF);
        fluxo.add(7, 9, INF);
        fluxo.add(9, 11, B*k);
    }
    if(C != 0){
        fluxo.add(3, 10, INF);
        fluxo.add(5, 10, INF);
        fluxo.add(6, 10, INF);
        fluxo.add(7, 10, INF);
        fluxo.add(10,11, C*k);
    }

    ll resp = fluxo.max_flow(0,11);
    debug(A);
    debug(B);
    debug(C);

    debug(resp);
    debug((a+b+c+ab+bc+ac+abc));
    if(resp == (a+b+c+ab+bc+ac+abc)) return true;
    return false;
}

bool funfa(ll L){
    for(ll A = L; A >= 0; --A){
        for(ll B = L - A; B >= 0; --B){
            ll C = L - A - B;
            bool aux = testa_fluxo(A, B, C);
            if(aux) return true;
        }
    }
    return false;
}

void solve() {
    cin >> k;
    cin >> a >> b >> c >> ab >> bc >> ac >> abc;
    debug((a+b+c+ab+bc+ac+abc));
       
    ll offset = a/k + b/k + c/k;
    a %= k; b%= k; c %= k;
    ab = adjust(ab, 3, k, offset);
    bc = adjust(bc, 3, k, offset);
    ac = adjust(ac, 3, k, offset);
    abc = adjust(abc, 7, k, offset);

    debug((a+b+c+ab+bc+ac+abc));
       
    ll left = 0;
    ll right = 17;
    ll ans = INF;
    while(left <= right){
        ll mid = (left+right)/2;
        if(funfa(mid)){
            ans = mid;
            right = mid-1;
        }else{
            left = mid+1;
        }
    }

    debug(offset);
    if(ans == INF){
        cout << "# " << offset << ln;
    }else{
        cout << ans + offset << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}