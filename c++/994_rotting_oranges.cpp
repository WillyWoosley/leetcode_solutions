class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> rotten;
        int oranges = 0;
        int last_rot = 0;

        // Put all rotten oranges in queue, and keep track of total
        // count of (rotten and non-rotten) oranges
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    oranges += 1;
                    if (grid[i][j] == 2) {
                        rotten.push(make_tuple(last_rot, i, j));
                    }
                }
            }
        }

        // BFS on rotten oranges, keeping track of the 'time' at which
        // individual oranges rotted
        while (!rotten.empty()) {
            oranges -= 1;
            int rot_time, x, y;
            tie(rot_time, x, y) = rotten.front();
            rotten.pop();

            // Update last_rot to be latest time seen
            last_rot = max(last_rot, rot_time);

            // Enqueue all neighbors, who are now 'rotten'
            if (x > 0 && grid[x-1][y] == 1) {
                rotten.push(make_tuple(rot_time + 1, x - 1, y));
                grid[x-1][y] = 2;
            }
            if (x < grid.size() - 1 && grid[x+1][y] == 1) {
                rotten.push(make_tuple(rot_time + 1, x + 1, y));
                grid[x+1][y] = 2;
            }
            if (y > 0 && grid[x][y-1] == 1) {
                rotten.push(make_tuple(rot_time + 1, x, y - 1));
                grid[x][y - 1] = 2;
            }
            if (y < grid[0].size() - 1 && grid[x][y + 1] == 1) {
                rotten.push(make_tuple(rot_time + 1, x, y + 1));
                grid[x][y+1] = 2;
            }
        }

        // If still non-rotten oranges, -1, else latest rot
        return (oranges > 0 ? -1 : last_rot);
    }
};
