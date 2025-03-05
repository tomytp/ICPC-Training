#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<ll>> tree;
stack<ll> curr_filho;
vector<ll> pai;
vector<bool> dead;
vector<bool> visited;
ll king = 0;

void continue_dfs(ll curr){
    debug(curr);
    if(!dead[curr]){
        king = curr; 
        cout << king+1 << ln;
        return; 
    }

    ll valor = curr_filho.top();
    curr_filho.pop();

    if(valor < tree[curr].size()){
        curr_filho.push(valor+1);
        curr_filho.push(0);
        continue_dfs(tree[curr][valor]);
    }else if(curr != 0){
        continue_dfs(pai[curr]);
    }

}

int main(){
    _; ll q, v=0; cin >> q;
    pai.push_back(0);
    dead.resize(q+1, false);
    visited.resize(q+1, false);
    tree.resize(q+1);

    curr_filho.push(0);

    forn(i, 0, q){
        ll a, b; cin >> a >> b;
        b--;
        if(a == 1){
            v++;
            pai.push_back(b);
            tree[b].push_back(v);
        }
        if(a == 2){
            dead[b] = true;
            if(king == b) continue_dfs(king);
            else cout << king + 1 << ln;
        }
    }

    return 0;
}