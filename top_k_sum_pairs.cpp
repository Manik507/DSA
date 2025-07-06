#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // Sort both arrays in descending order
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        // Max-heap to store sum and their indices
        priority_queue<pair<int, pair<int, int>>> pq;

        // Set to track which index pairs we have already used
        set<pair<int, int>> vis;

        // Vector to store final answers
        vector<int> ans;
        int n = a.size();

        // Push the first largest sum (first elements of both arrays)
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});

        // Keep adding top K largest sums
        while (ans.size() < k) {
            auto top = pq.top();
            pq.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back(sum);  // store current largest sum

            // If possible, add next pair (i+1, j)
            if (i < n-1 && vis.find({i+1, j}) == vis.end()) {
                pq.push({a[i+1] + b[j], {i+1, j}});
                vis.insert({i+1, j});
            }

            // If possible, add next pair (i, j+1)
            if (j < n-1 && vis.find({i, j+1}) == vis.end()) {
                pq.push({a[i] + b[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }
        return ans;
    }
};

int main() {
    // Example input arrays
    vector<int> a = {4, 2, 1};
    vector<int> b = {5, 3, 1};
    int k = 4;

    Solution obj;
    vector<int> result = obj.topKSumPairs(a, b, k);

    // Print the top K sum pairs
    cout << "Top " << k << " sum pairs: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
