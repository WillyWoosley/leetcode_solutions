class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, cur_longest = 0, cur_start = 0;
        unordered_map<char, int> longest_chars;

        for (int i = 0; i < s.length(); i++) {
            if (longest_chars.find(s[i]) == longest_chars.end() || 
                longest_chars.find(s[i])->second < cur_start)
            {
                cur_longest += 1;
            } else {
                longest = max(longest, cur_longest);
                cur_start = longest_chars[s[i]] + 1;
                cur_longest = (i + 1) - cur_start;
            }

            longest_chars[s[i]] = i;
        }

        return max(longest, cur_longest);
    }
};
