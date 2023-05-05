class Solution {
private:
    // Check if passed character is a vowel
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        } else {
            return false;
        }
    }
public:
    int maxVowels(string s, int k) {
        int max_vow = 0, cur_max = 0;

        // Calculate number of vowels in initial window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                cur_max += 1;
            }
        }
        max_vow = cur_max;

        // Use sliding window to iterate over, adding and subtracting as
        // vowels enter and exit the window
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i-k])) {
                cur_max -= 1;
            }
            if (isVowel(s[i])) {
                cur_max += 1;
                max_vow = max(max_vow, cur_max);
            }
        }

        return max_vow;
    }
};
