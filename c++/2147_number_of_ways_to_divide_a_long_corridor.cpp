class Solution {
public:
    int numberOfWays(string corridor) {
        long result = 1;
        int modulo = 1000000007;
        
        int i = 0;
        while (i < corridor.length()) {
            // Iterate until we have a segment with two chairs
            int chair_count = 0;
            while (i < corridor.length() && chair_count != 2) {
                if (corridor[i] == 'S') {
                    chair_count += 1;
                }
                i++;
            }

            // If run off end and odd chairs, no partitions
            if (chair_count != 2) {
                return 0;
            }

            // Count number of plants between our chair pair and next chair pair
            int plant_count = 0;
            while (i < corridor.length() && corridor[i] == 'P') {
                plant_count += 1;
                i++;
            }

            // If in final segment, plants don't matter, reset count
            if (i == corridor.length()) {
                plant_count = 0;
            }

            // Add number of new partitions to running result, leverage modulo magic
            result = (result * (plant_count + 1)) % modulo;
        }

        return (int) result;
    }
};
