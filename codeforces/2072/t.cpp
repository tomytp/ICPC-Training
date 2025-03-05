#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        unsigned int k;
        cin >> n >> k;
        
        vector<unsigned int> row(n);
        
        // Generate the nth row in O(n) time
        for (int j = 1; j <= n; j++) {
            // The key observation: If (j & n) == j, then the value is k
            if ((j & n) == j) {
                row[j-1] = k;
            } else {
                row[j-1] = 0;
            }
        }
        
        // Print the row
        for (int j = 0; j < n; j++) {
            cout << row[j];
            if (j < n-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}