class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one_count = 0;

        while (n > 0) {
            if (n & 1 != 0) {
                one_count++;
            }
            n = n >> 1;
        }

        return one_count;
    }
};
