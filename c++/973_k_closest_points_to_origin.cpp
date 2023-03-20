class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> k_biggest;

        // Maintain priority queue with k biggest distances found in points
        for (vector<int> point : points) {
            int point_dist = pow(point[0], 2) + pow(point[1], 2); // no sqrt to remove potential precision loss
            if (k_biggest.size() >= k) {
                if (k_biggest.top().first > point_dist) {
                    k_biggest.pop();
                    k_biggest.emplace(point_dist, point);
                }
            } else {
                k_biggest.emplace(point_dist, point);
            }
        }

        // Transfer priority queue contents to result vector
        // (probably a more efficient way to do this part if you're a C++ wizard)
        vector<vector<int>> res;
        while (!k_biggest.empty()) {
            res.push_back(k_biggest.top().second);
            k_biggest.pop();
        }

        return res;
    }
};
