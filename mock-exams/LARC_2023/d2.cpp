#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

#define forn(i, s, e) for(ll i = s; i < e; i++)
#define FAST_CIN ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(), x.end()
#define ln "\n"
#define dbg(x) cout <<#x<<" = "<< x << ln

int compare(string guess, string secret, string xfeedback){
    string nfeedback = xfeedback;
    forn(i, 0, 5){
        if (guess[i] == secret[i]) nfeedback[i] = '*';
        else if (secret.find(guess[i]) != secret.npos) nfeedback[i] = '!';
        else nfeedback[i] = 'X';
    }
    return nfeedback == xfeedback ? 1 : 0;
}

int main() {
    FAST_CIN;
    ll n, g, counter=0;
    cin >> n;
    vector<string> dict(n);
    string feedback;
    forn(i,0,n){
        cin >> dict[i];
    }
    cin >> g;
    forn(i, 0, g){
        cin >> feedback;
        counter = 0;
        forn(i, 0, n){
            counter+=compare(dict[i], dict[0], feedback);
        }
        cout << counter << ln;
    }
}