class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> to_visit;
        int province_count = 0; // i.e. number of disjoint graphs
        int n = isConnected.size();

        // Go through all cities, and start a BFS on every unvisited city you find
        for (int i = 0; i < n; i++) {
        // Note: we will used isConnected[i][0] to keep track of whether or
        // not i has been visited, since we know i=0 will always be enqueued,
        // and we therefore get around an extra O(n) memory 'visited' vector
            if (isConnected[i][0] != -1) {
                province_count += 1;
                isConnected[i][0] = -1;
                to_visit.push(i);

                // Do BFS
                while (!to_visit.empty()) {
                    int cur_city = to_visit.front();
                    to_visit.pop();                  

                    for (int direct = 0; direct < n; direct++) {
                        if (isConnected[cur_city][direct] == 1 && isConnected[direct][0] != -1) {
                            isConnected[direct][0] = -1;
                            to_visit.push(direct);
                        }
                    }
                }
            }
        }

        return province_count;
    }
};
