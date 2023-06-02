class Solution {
private:
    // Do a DFS rooted on start, and return the number of bombs detonated
    // by starting from start
    int dfs(int start, vector<vector<int>>& adjacency) {
        stack<int> to_visit;
        vector<bool> visited(adjacency.size(), false);

        int bombs_det = 0;
        to_visit.push(start);
        visited[start] = true;
        while (!to_visit.empty()) {
            int cur = to_visit.top();
            to_visit.pop();
            bombs_det += 1;

            for (int edge : adjacency[cur]) {
                if (!visited[edge]) {
                    to_visit.push(edge);
                    visited[edge] = true;
                }
            }
        }

        return bombs_det;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adjacency(bombs.size());

        // Create an adjacency list representation of a graph of bombs,
        // where each node is a bomb and each edge represents causing detonation
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = 0; j < bombs.size(); j++) {
                // Don't compare to self
                if (i == j) {
                    continue;
                }

                // Check if bombs[i] would detonate bombs[j] by checking
                // Euclidian distance
                long delta_x = bombs[i][0] - bombs[j][0];
                long delta_y = bombs[i][1] - bombs[j][1];
                long radius_i = bombs[i][2];
                if (pow(radius_i, 2) >= pow(delta_x, 2) + pow(delta_y, 2)) {
                    adjacency[i].push_back(j);
                }
            }
        }

        // Do a DFS rooted on each node
        int max_bomb = 1;
        for (int i = 0; i < bombs.size(); i++) {
            int max_i = dfs(i, adjacency);
            max_bomb = max(max_bomb, max_i);
        }

        return max_bomb;
    }
};
