#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using v64 = vector<ll>;
using p64 = pair<ll, ll>;

#define ln '\n'
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define dbg(x) cout << #x << " = " << ln
#define forn(i, s, e) for(i = s; i < e; i++)

int main() {
    FAST_CIN;
    p64 x,y,z;
    p64 a,b,c;
    cin >> z.first >> z.second;    
    cin >> x.first >> x.second;    
    cin >> y.first >> y.second;    

    a.first = y.first + z.first - x.first;
    a.second = y.second + z.second - x.second;
    
    b.first = x.first + z.first - y.first;
    b.second = x.second + z.second - y.second;
    
    c.first = x.first + y.first - z.first;
    c.second = x.second + y.second - z.second;

    cout << a.first << ' ' << a.second << ln;
    cout << b.first << ' ' << b.second << ln;
    cout << c.first << ' ' << c.second << ln;

}
