
#include <iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        char ch = 'a';
        int size = 1;

        // Find size of final string after enough expansions
        while (size < k)
            size *= 2;

        // Binary traverse without creating string
        while (size > 1) {
            size /= 2;
            if (k > size) {
                ch += 1;
                k -= size;
            }
        }
        return ch;
    }
};

int main() {
    Solution sol;
    int k;

    cout << "Enter the value of k: ";
    cin >> k;

    char result = sol.kthCharacter(k);
    cout << "The " << k << "th character is: " << result << endl;

    return 0;
}
