class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;

        sort(nums.begin(), nums.end());
        int last_seen = nums[0] - 1;

        // For each index i, two pointer from back and front of sorted array
        // to find the 2sum which combine with it for 0
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] != last_seen) {
                last_seen = nums[i];
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[i] + nums[l] + nums[r] == 0) {
                        sums.push_back({nums[i], nums[l], nums[r]});
                        int last_l = nums[l];
                        while (last_l == nums[l] && l < r) {
                            l++;
                        }
                    } else if (nums[i] + nums[l] + nums[r] > 0) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }

        return sums;
    }
};
