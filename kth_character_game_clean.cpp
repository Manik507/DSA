
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        long long size = 1;       // start size as 1 (word = 'a')
        int lastindex = 0;
        int shiftcount = 0;

        // Find when total size >= k after applying operations
        for (int i = 0; i < n; i++) {
            size *= 2;            // each operation doubles the size
            if (size >= k) {
                lastindex = i;    // record the last operation needed
                break;
            }
        }

        // Work backwards from lastindex to 0
        for (int i = lastindex; i >= 0; i--) {
            size /= 2;            // halve the size as we reverse steps
            if (k > size) {       // if k is in second half
                k -= size;        // move k to corresponding position in first half
                if (operations[i] == 1) {
                    shiftcount++; // increment shift count if operation was type 1
                }
            }
        }

        // Final character is 'a' shifted by (shiftcount % 26)
        return (char)('a' + (shiftcount % 26));
    }
};

int main() {
    long long k;
    int n;
    cout << "Enter k: ";
    cin >> k;
    cout << "Enter number of operations: ";
    cin >> n;
    vector<int> operations(n);
    cout << "Enter operations (0 or 1): ";
    for (int i = 0; i < n; i++) cin >> operations[i];

    Solution obj;
    char result = obj.kthCharacter(k, operations);
    cout << "The " << k << "-th character is: " << result << endl;

    return 0;
}
