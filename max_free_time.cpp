
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(); // total number of events
        int time = 0;             // total time of k consecutive events
        int maxFree = INT_MIN;    // maximum free time found

        // go through all events one by one
        for (int i = 0; i < n; ++i) {
            // add current event's duration to total time
            time += endTime[i] - startTime[i];

            // find left boundary of free time
            int l = (i < k) ? 0 : endTime[i - k];

            // find right boundary of free time
            int r = (i == n - 1) ? eventTime : startTime[i + 1];

            // total time between l and r
            int gap = r - l;

            // free time left after attending events
            int timeleft = gap - time;

            // update maximum free time
            maxFree = max(maxFree, timeleft);

            // if we have considered k events, remove the first one from total time
            if (i >= k - 1)
                time -= endTime[i - k + 1] - startTime[i - k + 1];
        }

        // return the largest free time found
        return maxFree;
    }
};

int main() {
    Solution obj;
    int eventTime = 20;
    int k = 2;
    vector<int> startTime = {2, 6, 9, 15};
    vector<int> endTime = {4, 7, 12, 17};

    cout << "Maximum Free Time: " << obj.maxFreeTime(eventTime, k, startTime, endTime) << endl;

    return 0;
}
