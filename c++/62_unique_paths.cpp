class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> unique_paths(m, vector<int>(n, 0));

        // Initialize first row and first column to be all 1
        for (int i = 0; i < m; i++) {
            unique_paths[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            unique_paths[0][i] = 1;
        }

        // Go through row by row and calculate number of unique paths to every entry
        // on the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                unique_paths[i][j] = unique_paths[i-1][j] + unique_paths[i][j-1];
            }
        }

        return unique_paths[m-1][n-1];
    }
};
