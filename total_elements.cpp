
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int> mp; // store count of each element in window
        int result = 0;            // final result
        int i = 0, j = 0;          // window pointers
        int n = arr.size();        // total size

        while(j < n) {
            mp[arr[j]]++;          // add current element to window

            while(mp.size() > 2) { // if window has more than 2 different elements
                mp[arr[i]]--;      // reduce count of leftmost element
                if(mp[arr[i]] == 0) {
                    mp.erase(arr[i]); // remove it if count becomes zero
                }
                i++;               // move left pointer
            }

            result = max(result, j-i+1); // update maximum window length
            j++; // move right pointer
        }

        return result; // return final result
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int ans = obj.totalElements(arr);
    cout << "Maximum subarray size with at most 2 different elements = " << ans << endl;

    return 0;
}
