
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of Longest Increasing Subsequence (LIS)
int lengthOfLIS(vector<int>& nums) {
    vector<int> temp; // This will store the potential ends of increasing subsequences

    for (int num : nums) {
        // Use lower_bound to find the index where 'num' can be placed
        auto it = lower_bound(temp.begin(), temp.end(), num);

        if (it == temp.end()) {
            // If 'num' is greater than all elements in 'temp', add it to the end
            temp.push_back(num);
        } else {
            // Otherwise, replace the first element in 'temp' which is >= 'num'
            *it = num;
        }
    }

    // The size of 'temp' gives us the length of the Longest Increasing Subsequence
    return temp.size();
}

int main() {
    // Sample input array
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    // Call the function and print the result
    cout << "Length of LIS: " << lengthOfLIS(arr) << endl;

    return 0;
}
