class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> to_visit;
        int island_count = 0;
        int row_max = grid.size() - 1, col_max = grid[0].size() - 1;

        // BFS on island grid
        for (int i = 0; i <= row_max; i++) {
            for (int j = 0; j <= col_max; j++) {
                if (grid[i][j] == 0) {
                    bool on_boundary = false;
                    to_visit.push(make_pair(i, j));

                    while (!to_visit.empty()) {
                        // Pop coords and update
                        int x, y;
                        tie(x, y) = to_visit.front();
                        to_visit.pop();
                        grid[x][y] = 1;

                        // Check if coords are on a boundary
                        if (x == 0 || x == row_max || y == 0 || y == col_max) {
                            on_boundary = true;
                        }

                        // Enqueue all neighboring island
                        if (x > 0 && grid[x-1][y] == 0) {
                            to_visit.push(make_pair(x-1, y));
                        }
                        if (x < row_max && grid[x+1][y] == 0) {
                            to_visit.push(make_pair(x+1, y));
                        }
                        if (y > 0 && grid[x][y-1] == 0) {
                            to_visit.push(make_pair(x, y-1));
                        }
                        if (y < col_max && grid[x][y+1] == 0) {
                            to_visit.push(make_pair(x, y+1));
                        }
                    }

                    // If island is on boundary, is cannot be totally surrounded by water,
                    // otherwise it is to incr count
                    if (!on_boundary) {
                        island_count += 1;
                    }
                }
            }
        }

        return island_count;
    }
};
