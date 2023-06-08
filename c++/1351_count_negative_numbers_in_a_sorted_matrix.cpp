class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int neg_count = 0;
        int n = grid[0].size(), first_neg = 0;

        for (int i = grid.size() - 1; i >= 0; i--) {
            while (first_neg < n && grid[i][first_neg] >= 0) {
                first_neg += 1;
            }
            neg_count += (n - first_neg);
        }

        return neg_count;
    }
};
