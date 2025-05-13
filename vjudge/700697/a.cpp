#include <bits/stdc++.h>
#define ln '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int testCases, k, t, n;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        cin >> k >> t >> n;

        int sacador = 0; // Thiago começa sacando
        // sacador = 0 -> Thiago || sacador = 1 -> Nathan

        int totalPoints = t + n;
        int rodadasPassadas = totalPoints / k;


        if (totalPoints >= k) {
            if (rodadasPassadas % 2 == 1) {
                sacador = 1;
            }
        }

        cout << k << " " << t << " " << n << " " << (sacador == 0 ? "Thiago" : "Nathan") << ln;
    }

    return 0;
}
