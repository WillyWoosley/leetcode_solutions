class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_total = 0;
        int nums_total = 0;

        for (int i = 0; i <= nums.size(); i++) {
            expected_total += i;
        }

        for (int n : nums) {
            nums_total += n;
        }

        return (expected_total - nums_total);
    }
};
