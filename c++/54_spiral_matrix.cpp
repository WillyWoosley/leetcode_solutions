class Solution {
private:
    enum Direction { right, left, up, down };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral_vec;
        int r_min = 0, r_max = matrix.size() - 1, c_min = 0, c_max = matrix[0].size() - 1;
        int cur_r = 0, cur_c = 0;
        Direction cur_travel = right;
        
        while (r_min <= r_max && c_min <= c_max) {
            spiral_vec.push_back(matrix[cur_r][cur_c]);
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

        return spiral_vec;
    }
};
