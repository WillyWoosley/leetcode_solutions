class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> char_count;
        int longest = 0;
        bool single = false;

        for (char c : s) {
            if (char_count.find(c) == char_count.end()) {
                char_count[c] = 1;
            } else {
                char_count[c] += 1;
            }
        }

        for (auto& [c, count] : char_count) {
            if (count % 2 == 0) {
                longest += count;
            } else {
                if (single) {
                    longest += count - 1;
                } else {
                    longest += count;
                    single = true;
                }
            }
        }    

        return longest;
    }
};
