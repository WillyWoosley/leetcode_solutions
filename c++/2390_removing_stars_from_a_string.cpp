class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int star_count = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                star_count += 1;
            } else if (star_count > 0) {
                star_count -= 1;
            } else {
                ans.push_back(s[i]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
