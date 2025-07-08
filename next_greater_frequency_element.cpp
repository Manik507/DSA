
// C++ Program for Next Greater Frequency Element
// using stack and hashmap (unordered_map)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size(); // total elements in array
        vector<int> res(n, -1); // initialize result array with -1
        unordered_map<int, int> mp; // to store frequency of each element
        stack<int> st; // stack to store indexes

        // Step 1: count frequency of each number
        for (int it : arr)
            mp[it]++;

        // Step 2: iterate over array elements one by one
        for (int i = 0; i < n; i++) {
            // If current element's frequency is greater than
            // frequency of element at stack top, then
            // update result for that index and pop it
            while (!st.empty() && mp[arr[i]] > mp[arr[st.top()]]) {
                res[st.top()] = arr[i]; // update result
                st.pop(); // remove index from stack
            }
            // push current index to stack
            st.push(i);
        }

        // Remaining indexes in stack have no greater frequency element to right
        // so result remains -1 for them

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 1, 2, 3, 4, 2, 1}; // input array
    vector<int> result = obj.findGreater(arr); // get result

    // print result array
    cout << "Next Greater Frequency Elements: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
