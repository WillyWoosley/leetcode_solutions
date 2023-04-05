class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long cur_max = 0, pref_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            pref_sum += nums[i];
            // maximum is the larger of everything in the prefix were it to
            // be evenly distributed, or the already seen max, since we cannot
            // move anything over that max to the right to rebalance at this
            // point.
            //
            // + i in numerator is to facillitate int round up division
            cur_max = max(cur_max, (pref_sum + i) / (i + 1));
        }

        return cur_max;
    }
};
