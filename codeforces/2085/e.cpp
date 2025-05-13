#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// Function to check if a given k is valid
bool isValidK(const vector<int>& a, const vector<int>& b, int k) {
    int n = a.size();
    
    // Calculate frequency of elements in a % k
    map<int, int> freqAModK;
    for (int val : a) {
        freqAModK[val % k]++;
    }
    
    // Calculate frequency of elements in b
    map<int, int> freqB;
    for (int val : b) {
        freqB[val]++;
    }
    
    // Check if frequencies match
    return freqAModK == freqB;
}

int findMagicNumber(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    
    // Find maximum element in b
    int maxB = *max_element(b.begin(), b.end());
    
    // Any valid k must be greater than maxB since all elements in b must be less than k
    int minK = maxB + 1;
    
    // Check if the arrays already have the same elements
    vector<int> sortedA = a, sortedB = b;
    sort(sortedA.begin(), sortedA.end());
    sort(sortedB.begin(), sortedB.end());
    
    if (sortedA == sortedB) {
        return min(minK, (int)1e9);
    }
    
    // Special case for k = 1 (all elements in b must be 0)
    if (maxB == 0) {
        bool allZeros = true;
        for (int val : b) {
            if (val != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) return 1;
    }
    
    // Check k = 2 explicitly (common case)
    if (maxB < 2 && isValidK(a, b, 2)) {
        return 2;
    }
    
    // Generate more potential k values
    set<int> potentialK;
    
    // Start with some small values of k
    for (int k = 2; k <= min(100, minK); k++) {
        potentialK.insert(k);
    }
    
    // Add minK to potential values
    potentialK.insert(minK);
    
    // Generate potential k values by finding numbers k where a[i] % k = b[j]
    // For each a[i] and b[j], find k where a[i] = b[j] (mod k)
    for (int aVal : a) {
        for (int bVal : b) {
            // Skip if bVal > aVal as no valid k can satisfy a[i] % k = b[j] if b[j] > a[i]
            if (bVal > aVal) continue;
            
            // For a[i] % k = b[j], we need a[i] - b[j] to be divisible by k
            // In other words, k is a divisor of (a[i] - b[j])
            int diff = aVal - bVal;
            
            // Skip if difference is 0 (no information about k)
            if (diff == 0) continue;
            
            // Find some divisors of diff that are greater than maxB
            for (int k = 2; k * k <= diff; k++) {
                if (diff % k == 0) {
                    if (k > maxB) potentialK.insert(k);
                    
                    int otherDiv = diff / k;
                    if (otherDiv > maxB) potentialK.insert(otherDiv);
                }
            }
        }
    }
    
    // Check each potential k value in ascending order
    for (int k : potentialK) {
        if (isValidK(a, b, k)) {
            return k;
        }
    }
    
    // No valid k found
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        cout << findMagicNumber(a, b) << endl;
    }
    
    return 0;
}