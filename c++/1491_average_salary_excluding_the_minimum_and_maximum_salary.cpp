class Solution {
public:
    double average(vector<int>& salary) {
        int min_s = INT_MAX, max_s = INT_MIN, total = 0;

        for (int s : salary) {
            total += s;
            min_s = min(min_s, s);
            max_s = max(max_s, s);
        }

        return (double)(total - (max_s + min_s)) / (double)(salary.size() - 2);
    }
};
