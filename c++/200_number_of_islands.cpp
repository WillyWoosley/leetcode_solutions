class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> to_visit;
        int island_count = 0;

        // Iterate over grid, checking all coord pairs for 'land,'
        // if found, perform BFS starting at that coord to remove
        // all 'land' attached to that 'island,' and continue
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    to_visit.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while (!to_visit.empty()) {
                        int x, y;
                        tie(x, y) = to_visit.front();
                        to_visit.pop();

                        // Enqueue all neighboring island, and zero out that land
                        // to prevent requeueing of already queued land
                        if (x > 0 && grid[x-1][y] == '1') {
                            to_visit.push(make_pair(x-1, y));
                            grid[x-1][y] = '0';
                        }
                        if (x < grid.size() - 1 && grid[x+1][y] == '1') {
                            to_visit.push(make_pair(x+1, y));
                            grid[x+1][y] = '0';
                        }
                        if (y > 0 && grid[x][y-1] == '1') {
                            to_visit.push(make_pair(x, y-1));
                            grid[x][y-1] = '0';
                        }
                        if (y < grid[0].size() - 1 && grid[x][y+1] == '1') {
                            to_visit.push(make_pair(x, y+1));
                            grid[x][y+1] = '0';
                        }
                    }
                    island_count += 1;
                }
            }
        }

        return island_count;
    }
};
