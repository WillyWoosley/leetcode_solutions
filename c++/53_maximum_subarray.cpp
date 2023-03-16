class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_seen = nums[0];
        int run_total = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (run_total < 0) {
                run_total = 0;
            }
            run_total += nums[i];
            max_seen = max(max_seen, run_total);
        }

        return max_seen;
    }
};
