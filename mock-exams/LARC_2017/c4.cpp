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
#define dbg(x) cout << #x << " = " << x << ln


int main(){
    //fast_cin();
    ll k, n; cin >> k >> n;
    v64 ocur(k, 0);

    forn(i, n) {
        ll aux; cin >> aux;
        ocur[--aux]++;
    }

    ll correct_freq = (n+1) / k;
    ll under = -1, upper = -1;
    forn (i, k) {
        if (ocur[i] == correct_freq -1) {
            if (under == -1) {
                under = i;
            } else {
                cout << "*" << ln;
                return 0;
            }
        }
        else if (ocur[i] == correct_freq + 1) {
            if (upper == -1) {
                upper = i;
            } else {
                cout << "*" << ln;
                return 0;
            }
        }
        else if (ocur[i] == correct_freq) {}
        else {
            cout << "*" << ln;
            return 0;
        }
    }
    if (under == -1 && upper == -1) {
        cout << "*" << ln;
        return 0;
    }

    if (upper != -1) {
        if (under != -1) {
            cout << '-' << upper + 1 << " +" << under + 1 << ln;
        } else {
            cout << '-' << upper + 1 << ln;
        }
    } else if (under != -1) {
        cout << "+" << under + 1 << ln;
    }
    
}