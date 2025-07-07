
// Problem: Next Greater Element
// For each element, find the next greater element on the right. If none, put -1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        stack<int> st;              // stack to store indices
        int n = arr.size();         // size of array
        vector<int> res(n, -1);     // answer array, initially -1
        
        // loop 2 times the array size to handle circular cases
        for(int i = 0; i < 2 * n; i++) {
            int idx = i % n;        // to wrap around array
            int num = arr[idx];     // current number

            // if current number is greater than element at top index of stack
            while(!st.empty() && num > arr[st.top()]) {
                res[st.top()] = num; // set next greater number
                st.pop();            // remove from stack
            }

            // push index only for first n elements
            if(i < n) {
                st.push(i);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 10};
    vector<int> result = sol.nextLargerElement(arr);

    cout << "Next greater elements: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Dry Run for arr = [4, 5, 2, 10]
Initially: stack = [], res = [-1, -1, -1, -1]

i=0 num=4 -> push 0 (stack=[0])
i=1 num=5 -> 5>4 -> res[0]=5, pop 0 (stack=[]) -> push 1 (stack=[1])
i=2 num=2 -> 2<5 -> push 2 (stack=[1,2])
i=3 num=10 -> 10>2 -> res[2]=10, pop 2 (stack=[1])
            -> 10>5 -> res[1]=10, pop 1 (stack=[]) -> push 3 (stack=[3])
i=4 num=4 -> no action (4<10)
i=5 num=5 -> no action (5<10)
i=6 num=2 -> no action (2<10)
i=7 num=10 -> no action (10==10)

Final result: [5, 10, 10, -1]
*/
