class Solution {
public:
    int partitionString(string s) {
        int substring_count = 0;
        unordered_map<char, int> char_loc;

        for (char c : s) {
            if (char_loc.find(c) != char_loc.end() &&
                char_loc[c] == substring_count) {
                substring_count += 1;
            }

            char_loc[c] = substring_count;
        }

        return substring_count + 1; // add 1 for final uncounted substring
    }
};
