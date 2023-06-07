class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int slope_x = coordinates[1][0] - coordinates[0][0];
        int slope_y = coordinates[1][1] - coordinates[0][1];

        for (int i = 2; i < coordinates.size(); i++) {
            if (slope_x * (coordinates[i][1] - coordinates[0][1]) != 
                slope_y * (coordinates[i][0] - coordinates[0][0])) {
                    return false;
            }
        }

        return true;
    }
};
