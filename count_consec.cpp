
#include<iostream>
using namespace std;

class Solution {
  public:
    int countConsec(int n) {
        // If n is 2, directly return 1 as per given condition
        if(n == 2) {
            return 1;
        }
        
        int third;          // To store the next Fibonacci number
        int first = 0;      // First number in Fibonacci (F0)
        int second = 1;     // Second number in Fibonacci (F1)
        int result = 1;     // Initialize result as 1 (starting value)

        // Loop from 3 to n
        for(int i = 3; i <= n; i++) {
            third = first + second;               // Calculate next Fibonacci number
            result = 2 * result + third;          // Update result as per given formula
            first = second;                       // Move to next Fibonacci number
            second = third;
        }
        return result;  // Return final result
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    cout << "Result: " << obj.countConsec(n) << endl;
    return 0;
}
