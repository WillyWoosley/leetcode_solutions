class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip_count = 0;
        bool lsb_a = false, lsb_b = false, lsb_c = false;
        
        // Move from right to left bitwise, comparing bits
        while (a != 0 || b != 0 || c != 0) {
            // Get everyone's LSB and shift
            lsb_a = a & 1;
            lsb_b = b & 1;
            lsb_c = c & 1;
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
            // Make comparison
            if (lsb_c) {
                if (!lsb_a && !lsb_b) {
                    flip_count += 1;
                }
            } else {
                if (lsb_a) {
                    flip_count += 1;
                }
                if (lsb_b) {
                    flip_count += 1;
                }
            }
        }
        
        return flip_count;
    }
};
