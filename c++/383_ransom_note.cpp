class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> char_count;

        for (char c : magazine) {
            char_count.find(c) == char_count.end() ? char_count[c] = 1 : char_count[c] += 1;
        }

        for (char c : ransomNote) {
            if (char_count.find(c) != char_count.end() && char_count[c] > 0) {
                char_count[c] -= 1;
            } else {
                return false;
            }
        }

        return true;
    }
};
