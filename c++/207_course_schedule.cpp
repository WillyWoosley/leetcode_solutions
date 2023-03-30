class Solution {
private:
    bool has_cycle(int node, vector<int>& status, vector<vector<int>>& graph) {
        bool cycle = false;

        for (int edge : graph[node]) {
            if (status[edge] == 1) {
                return true;
            } else if (status[edge] == 0) {
                status[edge] = 1;
                cycle = (cycle || has_cycle(edge, status, graph));
            }
        }

        status[node] = 2;
        return cycle;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Turn prerequisites into an adjacency list graph
        vector<vector<int>> graph(numCourses, vector<int> {});
        for (vector<int> prereq : prerequisites) {
            graph[prereq[0]].push_back(prereq[1]);
        }

        // Vector to keep track of individual graph node status
        // 0: unvisited, 1: on stack, 2: visited
        vector<int> status(numCourses, 0);
        for (int course = 0; course < numCourses; course++) {
            if (status[course] == 0) {
                status[course] = 1;
                bool cycle = has_cycle(course, status, graph);
                if (cycle) {
                    return false;
                }
            }
        }

        // No cycles detected, therefore all courses can be taken
        return true;
    }
};
