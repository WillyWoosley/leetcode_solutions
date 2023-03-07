class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> chars;

        // Populate hashmap with character frequencies from s
        for (char c : s) {
            if (chars.find(c) == chars.end()) {
                chars[c] = 1;
            } else {
                chars[c]++;
            }
        }

        // Check if t has same character frequencies
        for (char c : t) {
            if (chars.find(c) == chars.end() || chars[c] == 0) {
                return false;
            } else {
                chars[c]--;
                if (chars[c] == 0) {
                    chars.erase(c);
                }
            }
        }

        return chars.empty();
    }
};
