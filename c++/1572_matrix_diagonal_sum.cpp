class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int p1 = 0, p2 = mat[0].size() - 1;
        int sum = 0, cur_row = 0;

        while (cur_row < mat.size()) {
            if (p1 == p2) {
                sum += mat[cur_row][p1];
            } else {
                sum += (mat[cur_row][p1] + mat[cur_row][p2]);
            }

            p1 += 1;
            p2 -= 1;
            cur_row += 1;
        }

        return sum;
    }
};
