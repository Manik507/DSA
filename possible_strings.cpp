
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // function to count possible strings based on consecutive similar characters
    int possibleStringCount(string word) {
        int count = 0; // to store number of consecutive same characters

        // loop from 1 to word size
        for(int i = 1; i < word.size(); i++) {
            // if current char same as previous char
            if(word[i] == word[i-1]) {
                count++; // increase count
            }
        }

        // we add 1 to final count because:
        // if no consecutive same characters found, there is still 1 possible string
        // also because count starts from 0 but we always have at least one possible string
        return count + 1;
    }
};

int main() {
    string word;
    cout << "Enter string: ";
    cin >> word;

    Solution obj;
    int result = obj.possibleStringCount(word);
    cout << "Possible strings count = " << result << endl;

    return 0;
}
