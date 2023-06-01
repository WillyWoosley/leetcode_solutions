class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> to_visit;
        vector<pair<int, int>> adjacent = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        int n = grid.size();

        // In case top left is 1
        if (grid[0][0] == 0) {
            grid[0][0] = 1;
            to_visit.push({0, 0});
        }

        // BFS searching for bottom right, keeping track of
        // distance traversed in appropriate grid coords
        while (!to_visit.empty()) {
            auto [x, y] = to_visit.front();
            to_visit.pop();
            
            // Check if this is our destination
            if (x == n - 1 && y == n - 1) {
                return grid[x][y];
            }

            // Enqueue all unvisited neighbors, and update their distance
            // from the origin
            for (auto [change_x, change_y] : adjacent) {
                int new_x = x + change_x, new_y = y + change_y;
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0) {
                    grid[new_x][new_y] = grid[x][y] + 1;
                    to_visit.push({new_x, new_y});
                }
            }
        }

        return -1;
    }
};
