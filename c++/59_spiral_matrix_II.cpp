class Solution {
private:
    enum Direction { right, left, up, down };
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int r_min = 0, r_max = n - 1, c_min = 0, c_max = n - 1;
        Direction cur_travel = right;

        // Do a spiral traversal of the matrix, bringing in the bounds
        // on all sides as rows and columns are filled in as appropriate
        int cur_r = 0, cur_c = 0;
        for (int i = 1; i <= n * n; i++) {
            matrix[cur_r][cur_c] = i;

            switch (cur_travel) {
                case right:
                    if (cur_c == c_max) {
                        r_min += 1;
                        cur_travel = down;
                        cur_r += 1;
                    } else {
                        cur_c += 1;
                    }
                    break;
                case left:
                    if (cur_c == c_min) {
                        r_max -= 1;
                        cur_travel = up;
                        cur_r -= 1;
                    } else {
                        cur_c -= 1;
                    }
                    break;
                case up:
                    if (cur_r == r_min) {
                        c_min += 1;
                        cur_travel = right;
                        cur_c += 1;
                    } else {
                        cur_r -= 1;
                    }
                    break;
                case down:
                    if (cur_r == r_max) {
                        c_max -= 1;
                        cur_travel = left;
                        cur_c -= 1;
                    } else {
                        cur_r += 1;
                    }
                    break;
            }
        }

        return matrix;
    }
};
