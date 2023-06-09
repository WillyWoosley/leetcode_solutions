class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        char smallest = letters[0];

        while (l <= r) {
            int mid = (l + r) / 2;
            if (letters[mid] > target) {
                smallest = letters[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return smallest;
    }
};
