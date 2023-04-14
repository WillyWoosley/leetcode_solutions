class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.length(), vector<int>(s.length()));

        // Pre-populate initial 1-length row
        for (int i = 0; i < s.length(); i++) {
            memo[i][i] = 1;
        }

        // Bottom-up DP construction, checking through all different
        // substring lengths of size and utilizing memoized knowledge of
        // all substring maxes of size-1
        for (int i = 1; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                int l = j - i;
                int r = j;
                
                if (s[l] == s[r]) {
                    int palindrome_between = l <= r ? memo[l+1][r-1] : 0;
                    memo[l][r] = 2 + palindrome_between;
                } else {
                    memo[l][r] = max(memo[l][r-1], memo[l+1][r]);
                }
            }
        }

        return memo[0].back();
    }
};