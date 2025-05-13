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

set<ll> p_even, p_odd, m_even, m_odd;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

ll play_a(ll num){
    if(p_even.size() > 0){
        num += *p_even.begin();
        // cout << "+ " << *p_even.begin() << ln;
        // cout.flush();
        p_even.erase(p_even.begin());
    }
    if(m_odd.size() > 0){
        num *= *m_odd.begin();
        // cout << "* " << *m_odd.begin() << ln;
        // cout.flush();
        m_odd.erase(m_odd.begin());
    }

    return num;
}

ll play_b(ll num){
    num *= *m_even.begin();
    // cout << "* " << *m_even.begin() << ln;
    // cout.flush();
    m_even.erase(m_even.begin());

    return num;
}

ll play_c(ll num){
    num += *p_odd.begin();
    // cout << "+ " << *p_odd.begin() << ln;
    // cout.flush();
    p_odd.erase(p_odd.begin());

    return num;
}

ll read(ll num){
    ll x = uniform(0, 3);
    if(x == 0 or x == 1){
        return play_a(num);
    }
    if(x == 2){
        return play_b(num);
    }
    if(x == 3){
        return play_c(num);
    }
    return 0;
}

void solve(){
    ll n = uniform(1,10);
    forn(i, 0, n){
        char c = "+*"[uniform(0,1)]; ll a = uniform(0,1);
        // cout << c << a << ln;
        if(c == '+' and a%2 == 0) p_even.insert(a);
        if(c == '+' and a%2 == 1) p_odd.insert(a);
        if(c == '*' and a%2 == 0) m_even.insert(a);
        if(c == '*' and a%2 == 1) m_odd.insert(a);
    }

    ll num = uniform(0,1);
    // cout << num << ln;
    num = num%2;

    // cout << "----------\n";
    bool find_even = false;
    ll a = p_even.size() + m_odd.size();
    ll b = m_even.size();
    ll c = p_odd.size();

    if(b>= 2){
        find_even = true;
        // cout << "you" << ln;
        // cout.flush();
    }
    if(b == 1){
        if(c%2 == 1); // cout << "me" << ln;
        else{
            find_even = true;
            // cout << "you" << ln;
            // cout.flush();
        }
    }
    if(b == 0){
        if((c+num)%2 == 1); // cout << "me" << ln;
        else{
            find_even = true;
            // cout << "you" << ln;
            // cout.flush();
        }
    }

    if(find_even){
        do{
            num = read(num);
            a = p_even.size()+m_odd.size();
            b = m_even.size();
            c = p_odd.size();
            if(a + b + c == 0) break;

            if(c%2 == 1) num = play_c(num);
            else if(b>0) num = play_b(num);
            else if(c>0) num = play_c(num);
            else num = play_a(num);

            a = p_even.size()+m_odd.size(), b = m_even.size(), c = p_odd.size();
        } while(a+b+c > 0);
        if(num%2 == 1) cout << "deu merda" << ln;
    }

    if(!find_even){
        do{
            if(b>0) num = play_b(num);
            else if(c>0) num = play_c(num);
            else num = play_a(num);

            a = p_even.size() + m_odd.size(), b = m_even.size(), c = p_odd.size();
            if(a + b + c == 0) break;

            num = read(num);
            a = p_even.size() + m_odd.size(), b = m_even.size(), c = p_odd.size();
            if(a + b + c == 0) break;
        } while(a+b+c > 0);
        if(num%2 == 0) cout << "deu merda" << ln;
    }

}

int main(){
    ll t; cin >> t;
    forn(i, 0, t){
        solve();
        p_even.clear();
        p_odd.clear();
        m_even.clear();
        m_odd.clear();
    }

    return 0;
}