
// ✅ Maximum Subarray Problem - LeetCode (Kadane's Algorithm)
// 👉 This file contains two approaches:
// 1. Brute Force Approach (Commented)
// 2. Optimized Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------
// ✅ 1. Brute Force Approach (Time: O(N^2), Space: O(1))
// ----------------------------------------------------
// int maxSubArray(vector<int>& nums) {
//     int n = nums.size();
//     int msum = INT_MIN; // To store the maximum sum found so far
//     for (int st = 0; st < n; st++) {
//         int csum = 0; // current subarray sum
//         for (int end = st; end < n; end++) {
//             csum += nums[end]; // add current element to subarray sum
//             msum = max(msum, csum); // update max sum if current is greater
//         }
//     }
//     return msum; // return the max subarray sum
// }

// ----------------------------------------------------
// ✅ 2. Optimized Kadane’s Algorithm (Time: O(N), Space: O(1))
// ----------------------------------------------------
int maxSubArray(vector<int>& nums) {
    long long sum = 0;          // To track current sum
    long long maxSum = -1e9;    // To track the maximum sum so far (initialize with very small value)
    long long n = nums.size();  // Size of array

    for (long long i = 0; i < n; i++) {
        if (sum + nums[i] >= 0) {
            sum += nums[i];             // Extend current subarray
            maxSum = max(sum, maxSum);  // Update max sum
        } else {
            sum = 0; // Reset if subarray sum goes negative
        }
    }

    // Edge case: All numbers are negative
    if (maxSum == -1e9) {
        return *max_element(nums.begin(), nums.end());
    }
    return maxSum;
}

// 🔽 Example usage
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum = " << maxSubArray(nums) << endl;
    return 0;
}
