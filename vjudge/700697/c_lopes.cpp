#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct dtr {
  ll min;
  ll max;
  ll sum;
};

int main(void){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  ll tc;
  cin >> tc;
  vector<dtr> vec;
  ll op, elem;

  dtr dt;

  for(ll i = 0; i < tc; i++){
    cin >> op >> elem;
    
    switch (op) {
      case(1):
        if(i == 0){
          dt.max = elem;
          dt.sum = elem;
          dt.min = elem;

          vec.push_back(dt);
          break;
        }
        dt.max = max(dt.max, elem);
        dt.min = min(dt.min, elem);
        dt.sum += elem;
        vec.push_back(dt);
        break;
    case(2):
      cout << vec[elem - 1].max << "\n";
      vec.push_back(dt);
      break;
    
    case(3):
      cout << vec[elem - 1].min << "\n";
      vec.push_back(dt);
      break;

    case(4):
      cout << vec[elem - 1].sum << "\n";
      vec.push_back(dt);
      break;
    }
  }
}