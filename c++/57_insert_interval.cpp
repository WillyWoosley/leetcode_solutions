class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> new_intervals;
        bool new_inserted = false;

        for (int i = 0; i < intervals.size(); i++) {
            if (new_inserted || intervals[i][1] < newInterval[0]) {
                new_intervals.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    i++;
                }
                
                i--;
                new_intervals.push_back(newInterval);
                new_inserted = true;
            }
        }

        if (!new_inserted) {
            new_intervals.push_back(newInterval);
        }

        return new_intervals;
    }
};
