
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int i = 0, j = 0;          // window pointers
        int cnt = -1;              // to store final answer (-1 if no substring found)
        unordered_map<char, int> mp; // to count characters in current window

        while (j < n) {
            mp[s[j]]++;            // add current character to map

            // if number of different characters > k, shrink window from left
            while (mp.size() > k) {
                mp[s[i]]--;        // reduce count of character at i
                if (mp[s[i]] == 0)
                    mp.erase(s[i]); // remove it if count is zero
                i++;               // move left pointer
            }

            // if window has exactly k different characters, check length
            if (mp.size() == k) {
                cnt = max(cnt, j - i + 1); // update max length
            }

            j++; // move right pointer
        }

        return cnt;
    }
};

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    int ans = obj.longestKSubstr(s, k);
    cout << "Longest substring length with exactly " << k << " unique characters = " << ans << endl;

    return 0;
}
