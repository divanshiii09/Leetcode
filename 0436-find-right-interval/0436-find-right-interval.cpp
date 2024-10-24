class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // Step 1: Store the start points and their original indices
        vector<pair<int, int>> starts; // {start, index}
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        // Step 2: Sort the intervals based on start points
        sort(starts.begin(), starts.end());

        // Step 3: Prepare the result vector
        vector<int> result(n, -1);

        // Step 4: For each interval, find the right interval using binary search
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            // Binary search for the smallest start >= end
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (starts[mid].first >= end) {
                    result[i] = starts[mid].second;
                    right = mid - 1; // Continue searching to the left for a smaller valid start
                } else {
                    left = mid + 1;
                }
            }
        }

        return result;
    }
};
