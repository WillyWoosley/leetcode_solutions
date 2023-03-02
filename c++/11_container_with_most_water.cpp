class Solution {
public:
    int maxArea(vector<int>& height) {
       int l = 0;
       int r = height.size() - 1;
       int max_vol = 0;

       while (l < r) {
           int cur_vol = std::min(height[l], height[r]) * (r - l);
           if (cur_vol > max_vol) {
               max_vol = cur_vol;
           }

           if (height[l] < height[r]) {
               l++;
           } else {
               r--;
           }
       }

       return max_vol;
    }
};

