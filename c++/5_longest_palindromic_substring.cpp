class Solution {
public:
    string longestPalindrome(string s) {
        int l_max = 0, r_max = 0;
        int str_size = s.length();

        for (int i = 0; i < str_size; i++) {
            // Check for all palindromes of odd length centered at index i
            int r = i, l = i;
            while (l >= 0 && r <= str_size - 1 && s[l] == s[r]) {
                l -= 1;
                r += 1;
            }
            l += 1; // to return to previous correct indices
            r -= 1; // 
            if (r - l > r_max - l_max) {
                r_max = r;
                l_max = l;
            }

            // Check for all palindromes of even length centered at index i/i+1
            l = i, r = i + 1;
            while (l >= 0 && r <= str_size - 1 && s[l] == s[r]) {
                l -= 1;
                r += 1;
            }
            l += 1; // to return to previous correct indices
            r -= 1; // 
            if (r - l > r_max - l_max) {
                r_max = r;
                l_max = l;
            }
        }

        return s.substr(l_max, (r_max - l_max) + 1);
    }
};
