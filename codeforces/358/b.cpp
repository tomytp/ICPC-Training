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

int main(){
    F_;
    ll n; cin >> n;
    string correct = "<3";
    forn(i, 0, n) {
        string aux; cin >> aux;
        correct += aux;
        correct += "<3";
    }
    string code; cin >> code;
    
    ll a = 0, b = 0;
    while (a < correct.size() && b < code.size()) {
        if (correct[a] == code[b]) {
            a++; b++;
        } else {
            b++;
        }
    }
    if (a == correct.size()) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    P_; return 0;
}