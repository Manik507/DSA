
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxScoreFromSubarrayMins(vector<int>& arr) {
        int ans = INT_MIN;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            int sum = arr[i] + arr[i + 1];  // score from adjacent pair
            ans = max(ans, sum);
        }
        
        return ans;
    }
};

int main() {
    vector<int> arr = {4, 3, 5, 1};
    Solution obj;
    cout << "Maximum score is: " << obj.maxScoreFromSubarrayMins(arr) << endl;
    return 0;
}
