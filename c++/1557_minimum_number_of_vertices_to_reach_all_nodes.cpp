class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Mark all vectors that have an in edge
        vector<bool> has_in_edge(n, false);
        for (vector<int> edge : edges) {
            has_in_edge[edge[1]] = true;
        }

        // Create set of all nodes verticies with no in edge, which will be our min set
        vector<int> min_set;
        for (int i = 0; i < n; i++) {
            if (has_in_edge[i] == false) {
                min_set.push_back(i);
            }
        }

        return min_set;
    }
};
