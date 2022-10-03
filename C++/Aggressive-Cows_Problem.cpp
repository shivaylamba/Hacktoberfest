#include <bits/stdc++.h>
using namespace std;

// Function to check if we can place all cows with given distance
bool isCompatible(vector<int> inp, int dist, int cows) {         
    int n = inp.size();
    int cntCows = 1; // Store how many cows we placed
    int lastPlacedCow = inp[0]; // greedily we always place 1st cows on 0th position
    // Now traverse on array for remaining cows
    for (int i = 1; i < n; i++) {
        // if differnce between last placed cow and curr stall is greater or equal distance
        // means, we can place another cow here
        if (inp[i] - lastPlacedCow >= dist) {
            cntCows++; // indicates we plac a cow
            lastPlacedCow = inp[i]; // store curr stall position in last placed cow
        }
        // If we placed all cows we can return true, means at this distance we can place all given cows
        if (cntCows == cows) return true;
    }
    // If we can't place
    return false;
}

// Method - 1 Brute Force - TC O(maxD*n) SC O(1)
int aggressiveCows(vector<int> &inp, int n, int c) {
    // sort the input
    sort(inp.begin(), inp.end());

    //maxD -> maxDistance or gap we can make between cow
    int maxD = inp[n - 1] - inp[0];
    int ans = INT_MIN; // Store largest minimal distance

    // gap 1 to maxD
    for (int d = 1; d <= maxD; d++) 
        // If we can place cow d gaps
        if (isCompatible(inp, d, c))
            ans = max(ans, d); // update ans
        
    return ans;
}

// Method - 2 Binary Search TC O(nlog(maxD)) SC O(1)
int aggressiveCows(vector<int> &inp, int n, int c) {
    // Binary search on distance we can place cow
    // minimum distance -> low = 1
    // maximum distance -> high = inp[n-1] - inp[0]
    int low = 1, high = inp[n - 1] - inp[0];
    int ans = 0;
    // Applying binary search
    while (low <= high) {
        int mid = (low + high) >> 1;

        // If we can place cows with mid distance 
        if (isCompatible(inp, mid, c)) {
            low = mid + 1; // search for larger distance
            ans = mid; // mid always increase here so ans always maximum
        }
        // If we can't place cows, means current distance too big  
        else 
            high = mid - 1; // so search for smaller distance
        
    }
    return ans;
}


int main() {
    int n = 5, c = 3;
    vector<int> inp{1, 2, 8, 4, 9};

    int ans = aggressiveCows(inp, n, c);
    cout << "The largest minimum distance is " << ans << '\n';
}
