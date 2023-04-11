class Solution {
private:
    vector<vector<int>> generateSums(vector<int>& candidates, int min_index, int target) {
        // Invalid combo, so return nothing
        if (target < 0) {
            return {};
        } else if (target == 0) { // Combo valid, start building result
            return {{}};
        }

        vector<vector<int>> results;

        // Check all sub-targets for all candidates, but check from left to right and ensure no
        // calls to the right on the recursion tree try combos using candidates to the left in
        // the candidate array, thereby eliminating duplicates
        for (int i = min_index; i < candidates.size(); i++) {
            vector<vector<int>> sub_results = generateSums(candidates, i, target - candidates[i]);
            for (vector<int> sub_result : sub_results) {
                sub_result.push_back(candidates[i]);
                results.push_back(sub_result);
            }
        }

        return results;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return generateSums(candidates, 0, target);
    }
};
