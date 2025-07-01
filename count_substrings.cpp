
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // function to count substrings of length k with (k-1) different characters
    int substrCount(string &s, int k) {
        unordered_map<char, int> mp; // map to count characters
        int cnt = 0;                 // final answer

        if(k > s.size()) return 0; // if k bigger than string, no answer

        // add first k characters to map
        for(int i = 0; i < k; i++) {
            mp[s[i]]++;  // increase count
        }

        // check if different characters is k-1
        if(mp.size() == k-1) cnt++;

        // move window from k to end
        for(int j = k; j < s.size(); j++) {
            char charToAdd = s[j];        // new char coming
            char charToRemove = s[j - k]; // old char going

            mp[charToAdd]++;              // add new char
            mp[charToRemove]--;           // remove old char

            // if old char count is zero, remove from map
            if(mp[charToRemove] == 0) mp.erase(charToRemove);

            // check again if different characters is k-1
            if(mp.size() == k-1) cnt++;
        }

        return cnt;  // give final answer
    }
};

int main() {
    string s;
    int k;

    // take input from user
    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    // make object of class
    Solution obj;

    // call function and print answer
    int result = obj.substrCount(s, k);
    cout << "Number of substrings of length " << k << " with exactly " << k-1 << " different characters = " << result << endl;

    return 0;
}
