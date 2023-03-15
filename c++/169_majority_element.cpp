class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;

        for (int n : nums) {
            if (count == 0) {
                candidate = n;
                count = 1;
            } else {
                if (n == candidate) {
                    count += 1;
                } else {
                    count -= 1;
                }
            }
        }

        return candidate;
    }
};
