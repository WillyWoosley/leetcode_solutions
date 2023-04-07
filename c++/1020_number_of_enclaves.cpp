class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> to_visit;
        int enclave_count = 0;
        int row_size = grid.size() - 1, col_size = grid[0].size() - 1;

        // Check each grid entry, and if land is found do a BFS rooted on
        // those grid coordinates
        for (int i = 0; i <= row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == 1) {
                    int land_count = 0;
                    bool on_boundary = false;
                    grid[i][j] = 0;
                    to_visit.push(make_pair(i, j));

                    // Do a BFS
                    while (!to_visit.empty()) {
                        int x, y;
                        tie(x, y) = to_visit.front();
                        to_visit.pop();

                        // Keep track of how much land on this 'island', and
                        // whether or not it has any land on the grid edge
                        land_count += 1;
                        if (x == 0 || x == row_size || y == 0 || y == col_size) {
                            on_boundary = true;
                        }

                        // Enqueue neighbors
                        if (x > 0 && grid[x-1][y] == 1) {
                            grid[x-1][y] = 0;
                            to_visit.push(make_pair(x-1, y));
                        }
                        if (x < row_size && grid[x+1][y] == 1) {
                            grid[x+1][y] = 0;
                            to_visit.push(make_pair(x+1, y));
                        }
                        if (y > 0 && grid[x][y-1] == 1) {
                            grid[x][y-1] = 0;
                            to_visit.push(make_pair(x, y-1));
                        }
                        if (y < col_size && grid[x][y+1] == 1) {
                            grid[x][y+1] = 0;
                            to_visit.push(make_pair(x, y+1));
                        }
                    }

                    // If the land was on a boundary, it can be walked off of, otherwise
                    // add the land size to our enclave size count
                    if (!on_boundary) {
                        enclave_count += land_count;
                    }
                }
            }
        }

        return enclave_count;
    }
};
