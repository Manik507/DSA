class Solution {
public:
    /*
    // 🔍 Linear Search (Brute Force)
    // Time: O(n), Space: O(1)
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target)
                return i; // target found
        }
        return -1; // not found
    }
    */

    // 🔍 Optimized Binary Search in Rotated Sorted Array
    // Time: O(log n), Space: O(1)
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2; // avoid overflow

            if (nums[mid] == target) {
                return mid; // 🎯 Target found at index mid
            }

            // Check if the left half from st to mid is sorted
            if (nums[st] <= nums[mid]) {
                // If target lies within the sorted left half
                if (nums[st] <= target && target <= nums[mid]) {
                    end = mid - 1; // 🔄 Narrow search to left half
                } else {
                    st = mid + 1;  // 🔄 Search in right half
                }
            }
            // Otherwise, the right half from mid to end is sorted
            else {
                // If target lies within the sorted right half
                if (nums[mid] <= target && target <= nums[end]) {
                    st = mid + 1;  // 🔄 Narrow search to right half
                } else {
                    end = mid - 1; // 🔄 Search in left half
                }
            }
        }

        return -1; // ❌ Target not found
    }
};
