class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int max_time = 0;
        queue<int> to_inform;
        vector<vector<int>> subordinates(manager.size());

        // Create adjacency list, where node is manager and edge is subordinate
        for (int i = 0; i < manager.size(); i++) {
            if (manager[i] != -1) {
                subordinates[manager[i]].push_back(i);
            }
        }

        // Do BFS, starting from headID and working down tree, keeping track of max_time seen
        to_inform.push(headID);
        while (!to_inform.empty()) {
            int sup = to_inform.front();
            to_inform.pop();

            // If sup is a leaf node, then done, otherwise update and enqueue children
            if (subordinates[sup].size() > 0) {
                int sup_time = informTime[sup];
                max_time = max(max_time, sup_time);

                for (int sub : subordinates[sup]) {
                    informTime[sub] += sup_time;
                    to_inform.push(sub);
                }
            }
        }

        return max_time;
    }
};
