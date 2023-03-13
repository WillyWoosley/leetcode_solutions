class Solution {
private:
    int climbStairsHelper(int n, vector<int>& cache) {
        if (cache[n] != 0) {
            return cache[n];
        } else {
            int res = climbStairsHelper(n-1, cache) + climbStairsHelper(n-2, cache);
            cache[n] = res;
            return res;
        }
    }
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            vector<int> cache(n+1, 0);
            cache[1] = 1;
            cache[2] = 2;
            return climbStairsHelper(n, cache);
        }
    }
};
