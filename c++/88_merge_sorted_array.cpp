class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int max_1 = m - 1, max_2 = n - 1, write_to = nums1.size() - 1;

        while (write_to >= 0) {
            if (max_1 < 0) {
                nums1[write_to] = nums2[max_2];
                max_2 -= 1;
            } else if (max_2 < 0) {
                nums1[write_to] = nums1[max_1];
                max_1 -= 1;
            } else {
                if (nums1[max_1] > nums2[max_2]) {
                    nums1[write_to] = nums1[max_1];
                    max_1 -= 1;
                } else {
                    nums1[write_to] = nums2[max_2];
                    max_2 -= 1;
                }
            }

            write_to -= 1;
        }
    }
};
