class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> memo(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        // Generate memoization matrix, where every index represents the number of lines
        // from start to i and start to j in nums1 and nums2, respectively
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) { // Forgive weird indexing plz
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                } else {
                    memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
                }
            }
        }

        return memo[nums1.size()][nums2.size()];
    }
};
