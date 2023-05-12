class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> memo(questions.size());
        memo.back() = questions.back()[0];

        for (int i = questions.size() - 2; i >= 0; i--) {
            long long pick = questions[i][0] + 
                (questions[i][1] + i + 1 >= questions.size() ? 0 : memo[questions[i][1] + i + 1]);
            long long no_pick = memo[i+1];
            memo[i] = max(pick, no_pick);
        }

        return memo[0];
    }
};
