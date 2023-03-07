class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int ind = (r + l) / 2;
            if (nums[ind] == target) {
                return ind;
            } else if (nums[ind] < target) {
                l = ind + 1;
            } else {
                r = ind - 1;
            }
        }

        return -1;
    }
};
