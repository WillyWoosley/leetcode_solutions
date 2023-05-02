class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool zero = false;
        int neg_count = 0;

        for (int n : nums) {
            if (n < 0) {
                neg_count += 1;
            } else if (n == 0) {
                return 0;
            }
        }

        return neg_count % 2 == 0 ? 1 : -1;
    }
};
