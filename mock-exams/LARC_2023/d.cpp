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

int compare(string s, string guess, string ans){
    forn(i, 0, 5){
        if(guess[i]=='*' && s[i]!=ans[i]){
            return 0;
        } else if(guess[i]=='X' && ans.find(s[i]) != ans.npos){
            return 0;
        } else if (guess[i]=='!' && ans.find(s[i]) == ans.npos){
            return 0;
        }
    }
    return 1;
}

int main() {
    FAST_CIN;
    ll n, g, counter=0;
    cin >> n;
    vector<string> dict(n);
    string guess;
    forn(i,0,n){
        cin >> dict[i];
    }
    cin >> g;
    forn(i, 0, g){
        cin >> guess;
        forn(i, 0, n){
            counter+=compare(dict[i], guess, dict[0]);
        }
        cout << counter << ln;
        counter = 0;
    }
}