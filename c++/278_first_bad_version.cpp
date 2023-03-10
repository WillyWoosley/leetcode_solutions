// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l = 1, h = n;

        while (l <= h) {
            long int mid = (l + h) / 2;
            if (isBadVersion(mid)) {
                if (mid == 1 || !isBadVersion(mid - 1)) {
                    return mid;
                } else {
                    h = mid;
                }
            } else {
                l = mid + 1;
            }
        }

        return 1;
    }
};
