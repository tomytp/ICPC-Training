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
const ll ALF = 26;

string ask(string s, v64 perm) {
    string ans = s;
    forn(i, 0, perm.size()) {
        ans[perm[i] - 1] = s[i];
    }
    return ans;
}

void solve(ll n){
    v64 vec_ans(n);
    iota(vec_ans.begin(), vec_ans.end(), 1);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(vec_ans.begin(), vec_ans.end(), std::default_random_engine(seed));

    v64 vec(n);
    v64 resp(n,1);

    vector<string> s(4, string(n, 'a'));

    forn(i,0,n){
        ll aux = i;
        forn(j,0,4){
            s[j][i] += aux%ALF; 
            aux = aux/ALF;
        }

    }

    ll pot_alf = 1;

    forn(h, 0, 4){
        string inp = ask(s[h], vec_ans);

        forn(i,0,n){
            resp[i] += (inp[i]-'a')*pot_alf;
        }
        pot_alf *= ALF;
    }
    
    v64 resp2(n);

    forn(i,0,n){
        resp2[resp[i]-1] = i+1;
    }

    swap(resp, resp2);

    if (resp != vec_ans) {
        forn(i, 0, n) cout << vec_ans[i] << " \n"[i==n-1];
        forn(i, 0, n) cout << resp[i] << " \n"[i==n-1];
        exit(1);
    }
    return;
}

int main() {
    ll n; cin >> n;
    forn(i, 0, INF) {
        solve(n);
        cout << i << ln;
    }
}