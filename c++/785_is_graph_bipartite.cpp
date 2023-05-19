class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> a_side, b_side;
        queue<pair<int, int>> to_visit;

        // Essentially a BFS run, but with a good bit of extra cruft and data structures around
        // could probably be improved upon, but I'm not sure how
        for (int i = 0; i < graph.size(); i++) {
            if (a_side.find(i) == a_side.end() && b_side.find(i) == b_side.end()) {
                to_visit.push({0, i});
                while (!to_visit.empty()) {
                    auto[side, cur_node] = to_visit.front();
                    to_visit.pop();

                    // If need to insert but already on other partition, then its impossible
                    // otherwise insert it on appropriate partition and enqueue all edges not
                    // already explored
                    if (side == 0) {
                        if (b_side.find(cur_node) != b_side.end()) {
                            return false;
                        }

                        a_side.insert(cur_node);
                        for (int edge : graph[cur_node]) {
                            if (b_side.find(edge) == b_side.end()) {
                                to_visit.push({1, edge});
                            }
                        }
                    } else {
                        if (a_side.find(cur_node) != a_side.end()) {
                            return false;
                        }
                        b_side.insert(cur_node);
                        for (int edge : graph[cur_node]) {
                            if (a_side.find(edge) == a_side.end()) {
                                to_visit.push({0, edge});
                            }
                        }
                    }

                }
            }
        }

        return true;
    }
};
