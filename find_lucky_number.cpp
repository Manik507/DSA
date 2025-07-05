
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        int lucky = -1;

        // check for lucky number (number whose value equals its frequency)
        for (auto& [key, value] : freq) {
            if (key == value) {
                lucky = max(lucky, key);
            }
        }

        return lucky;
    }
};

int main() {
    vector<int> arr = {2, 2, 3, 4, 4, 4};
    Solution obj;
    cout << "Largest Lucky Number: " << obj.findLucky(arr) << endl;
    return 0;
}
