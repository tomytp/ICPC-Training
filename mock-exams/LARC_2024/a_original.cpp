#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define D_ false
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define forn(i, s, e) for(ll i = s; i < e; i++)

int main(){
    F_;
    string s;
    cin >> s;
    ll n = s.size();
    char a,b,c;
    ll counter = 0;
    for(int i = n-1; i >= 0; i--){
        counter++;
        if(s[i-1] >= s[i]) break;
    }
    cout << n - counter << '\n';
}