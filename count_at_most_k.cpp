
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int cnt = 0;                // final count of subarrays
        int i = 0, j = 0;           // window pointers
        unordered_map<int, int> mp; // map to track element counts

        while (j < n) {
            mp[arr[j]]++;           // add current element to map

            // if window has more than k distinct elements, shrink from left
            while (mp.size() > k) {
                mp[arr[i]]--;       // reduce count of arr[i]
                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]); // remove if count becomes zero
                i++;                // move left pointer
            }

            // number of subarrays ending at j is (j - i + 1)
            cnt += (j - i + 1);

            j++;                    // move right pointer
        }

        return cnt;                  // return total count
    }
};

int main() {
    int n, k;
    cout << "Enter array size and k: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    int ans = obj.countAtMostK(arr, k);
    cout << "Number of subarrays with at most " << k << " different elements = " << ans << endl;

    return 0;
}
