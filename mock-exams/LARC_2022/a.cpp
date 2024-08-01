#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<v64> vv64;
typedef vector<p64> vp64;

#define forn(i, e) for(ll i = 0; i < e; i++)
#define forsn(i, s, e) for(ll i = s; i < e; i++)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll) (x).size())

class UnionFind{
    private:
        v64 parent, rank;
    public:
        UnionFind(ll N){
            rank.assign(N+1,0);
            parent.assign(N+1,0);
            forn(i,N) parent[i] = i;
        }
        ll find(ll i){
            while(i != parent[i]) i = parent[i];
            return i;
        }
        bool isSameSet(ll i, ll j){
            return find(i) == find(j);
        }
        void unionSet(ll i, ll j){
            if (isSameSet(i,j)) return;
            ll x = find(i), y = find(j);
            if(rank[x] > rank[y]) parent[y] = x;
            else{
                parent[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        } 
};

char solve(ll i,vector<p64> viz,ll n){
    UnionFind uf(n);

    forn(j,n){
        if(j == i){
            continue;
        }

        uf.unionSet(j,viz[j].fi);
        uf.unionSet(j,viz[j].se);
    }

    if(uf.isSameSet(i,viz[i].fi) && uf.isSameSet(i,viz[i].se)){
        return 'Y';
    }

    return 'N';
}

int main(){
    fast_cin();
    ll n; cin >> n;
    vector<p64> viz(n);

    forn(i,n){
        cin >> viz[i].fi >> viz[i].se;  
        viz[i].fi--;
        viz[i].se--;
    }

    forn(i,n){
        cout << solve(i, viz ,n);
    }
    cout << ln; 
}