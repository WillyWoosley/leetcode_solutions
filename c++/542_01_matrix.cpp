class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, -1));
        queue<tuple<int, int, int>> visit;

        // Setup loop to enqueue all 0 containing indicies
        for (int i=0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    distance[i][j] = 0;
                    visit.emplace(make_tuple(0, i, j));
                }
            }
        }

        // BFS, keeping track of path length
        while (!visit.empty()) {
            int dist, i, j;
            tie(dist, i, j) = visit.front();
            visit.pop();

            if (i > 0 && distance[i-1][j] < 0) {
                distance[i-1][j] = dist + 1;
                visit.emplace(make_tuple(dist + 1, i - 1, j));
            }
            if (i < rows - 1 && distance[i+1][j] < 0) {
                distance[i+1][j] = dist + 1;
                visit.emplace(make_tuple(dist + 1, i + 1, j));
            }
            if (j > 0 && distance[i][j-1] < 0) {
                distance[i][j-1] = dist + 1;
                visit.emplace(make_tuple(dist + 1, i, j - 1));
            }
            if (j < cols - 1 && distance[i][j+1] < 0) {
                distance[i][j+1] = dist + 1;
                visit.emplace(make_tuple(dist + 1, i, j + 1));
            }
        }

        return distance;
    }
};
