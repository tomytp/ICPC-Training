#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define D_ true
#define F_ if(!D_)ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define P_ if(D_)cout<<"DEBUG\n"
#define forn(i, s, e) for(ll i = s; i < e; i++)
#define dbg(x) if(D_) cout << #x << " = " << x << "\n";

#define ln '\n'
#define dgb dbg

int main() {
    F_;
    ll k; cin >> k;
    string s; cin >> s;
    ll n = s.size();

    if (k == 2) {
        string aux1 = s, aux2 = s;
        ll comp1 = 0, comp2 = 0;
        forn(i, 0, n) {
            aux1[i] = i%2 == 0? '0' : '1';
            aux2[i] = i%2 == 0? '1' : '0';
            if(s[i] != aux1[i]) comp1++;
            else comp2++;
        }
        if (comp1 < comp2) {
            cout << comp1 << " " << aux1 << ln;
        } else {
            cout << comp2 << " " << aux2 << ln;
        }
        return 0;
    }

    vector<bool> v(n);
    forn(i, 0, n) {
        if (s[i] == '1') v[i] = true;
    }
    bool last_bit = v[0];
    ll counter = 1; ll sum = 0;
    forn(i, 1, n) {
        if (v[i] != last_bit) {
            counter = 1;
            last_bit = v[i];
            continue;
        }
        counter += 1;
        if (counter == k) {
            if (i < n-1 && v[i+1] == v[i]) {
                v[i] = !v[i];
            } else {
                v[i-1] = !v[i-1];
            }
            sum++;
            counter = 0;
        }
        last_bit = v[i];                       
    }

    cout << sum << " ";
    forn(i, 0, n) {
        if (v[i]) cout << '1';
        else cout << '0';
    }
    cout << ln;
}