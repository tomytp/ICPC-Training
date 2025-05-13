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

void read(){
    char c; ll a; cin >> c >> a;
    if(c == '+' and a%2 == 0) p_even.erase(a);
    if(c == '+' and a%2 == 1) p_odd.erase(a);
    if(c == '*' and a%2 == 0) m_even.erase(a);
    if(c == '*' and a%2 == 1) m_odd.erase(a);
}

void play_a(){
    if(p_even.size() > 0){
        cout << "+ " << *p_even.begin() << ln;
        cout.flush();
        p_even.erase(p_even.begin());
        return;
    }
    if(m_odd.size() > 0){
        cout << "* " << *m_odd.begin() << ln;
        cout.flush();
        m_odd.erase(m_odd.begin());
    }
}

void play_b(){
    cout << "* " << *m_even.begin() << ln;
    cout.flush();
    m_even.erase(m_even.begin());
}

void play_c(){
    cout << "+ " << *p_odd.begin() << ln;
    cout.flush();
    p_odd.erase(p_odd.begin());
}


int main(){
    ll n; cin >> n;
    forn(i, 0, n){
        char c; ll a; cin >> c >> a;
        if(c == '+' and a%2 == 0) p_even.insert(a);
        if(c == '+' and a%2 == 1) p_odd.insert(a);
        if(c == '*' and a%2 == 0) m_even.insert(a);
        if(c == '*' and a%2 == 1) m_odd.insert(a);
    }

    ll num;
    cin >> num;
    num = num%2;

    bool find_even = false;

    ll a = p_even.size() + m_odd.size();
    ll b = m_even.size();
    ll c = p_odd.size();

    if(b >= 2){
        find_even = true;
        cout << "you" << ln;
        cout.flush();
    }
    if(b == 1){
        if(c%2 == 1) cout << "me" << ln;
        else{
            find_even = true;
            cout << "you" << ln;
            cout.flush();
        }
    }
    if(b == 0){
        if((c+num)%2 == 1) cout << "me" << ln;
        else{
            find_even = true;
            cout << "you" << ln;
            cout.flush();
        }
    }

    if(find_even){
        do{
            read();
            
            a = p_even.size()+m_odd.size();
            b = m_even.size();
            c = p_odd.size();

            if(a + b + c == 0) break;

            if(c%2 == 1) play_c();
            else if(b>0) play_b();
            else if(c>0) play_c();
            else play_a();

            a = p_even.size()+m_odd.size(), b = m_even.size(), c = p_odd.size();
        } while(a+b+c > 0);
    }

    if(!find_even){
        do{
            if(b>0) play_b();
            else if(c>0) play_c();
            else play_a();

            a = p_even.size() + m_odd.size(), b = m_even.size(), c = p_odd.size();
            if(a + b + c == 0) break;

            read();
            a = p_even.size() + m_odd.size(), b = m_even.size(), c = p_odd.size();
            if(a + b + c == 0) break;
        } while(a+b+c > 0);
    }
    return 0;
}