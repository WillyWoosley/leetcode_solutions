class Solution {
public:
    int kthFactor(int n, int k) {
        int factor = 1;

        // Check all factors 1..sqrt(n)
        for (; factor * factor < n; factor++) {
            if (n % factor == 0) {
                k--;
                if (k == 0) {
                    return factor;
                }
            }
        }

        // Check all remaining factors, which must pair with some value 1..sqrt(n),
        // mapping in reverse order (sqrt(n)..1)
        
        // Ensure squares are checked
        factor = (factor * factor == n) ? factor : factor - 1;
        
        for (; factor >= 1; factor--) {
            if (n % factor == 0) {
                k--;
                if (k == 0) {
                    return n / factor;
                }
            }
        } 

        return -1;

    }
};
