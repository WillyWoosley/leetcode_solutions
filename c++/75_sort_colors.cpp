class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, cur = 0, r = nums.size() - 1;

        // Use three pointers, one to iterate and two which respectively
        // point to the next appropriate position to write a 0 or 2.
        // 1's are simply left where found
        while (cur <= r) {
            if (nums[cur] == 0) {
                swap(nums[l], nums[cur]);
                l += 1;
                cur += 1;
            } else if (nums[cur] == 2) {
                swap(nums[r], nums[cur]);
                r -= 1;
            } else {
                cur += 1;
            }
        }
    }
};
