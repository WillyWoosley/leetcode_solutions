class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> nums1_elem;

        for (int n1 : nums1) {
            nums1_elem[n1] = true;
        }

        unordered_set<int> nums2_unique;
        for (int n2 : nums2) {
            if (nums1_elem.find(n2) == nums1_elem.end()) {
                nums2_unique.insert(n2);
            } else {
                nums1_elem[n2] = false;
            }
        }

        vector<int> nums1_unique;
        for (auto [num, unique] : nums1_elem) {
            if (unique) {
                nums1_unique.push_back(num);
            }
        }

        return { nums1_unique, vector<int> (nums2_unique.begin(), nums2_unique.end()) };
    }
};
