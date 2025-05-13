#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    vector<int> divisors;
    divisors.push_back(1);
    int divisor = 2;
    
    while (n > 1) {
        if (divisor * divisor > n) {
            divisors.push_back(n);
            break;
        }

        while (n % divisor == 0) {
            divisors.push_back(divisor);
            n /= divisor;
        }
        divisor++;
    }

    for (int i = 0; i < divisors.size(); i++) {
        printf("%d", divisors[i]);
        if (i == divisors.size() - 1) {
            printf("\n");
        } else {
            printf(" x ");
        }
    }
}

int main() {    
    int n;
    while (scanf("%d",&n) != EOF) {
         solve(n);
    }
    
    return 0;
}