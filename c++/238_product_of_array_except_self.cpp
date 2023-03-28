class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l_product(nums.size());
        vector<int> r_product(nums.size());

        // Calculate the product of all values up to but not including
        // the current index, from the left to index
        l_product[0] = 1;
        for (int i = 1; i < l_product.size(); i++) {
            l_product[i] = nums[i-1] * l_product[i-1];
        }

        // Calculate the product of all value up to but not including
        // the current index, from the right to the index
        r_product[r_product.size() - 1] = 1;
        for (int i = r_product.size() - 2; i >= 0; i--) {
            r_product[i] = nums[i+1] * r_product[i+1];
        }

        // Find the product of the left and right subproducts
        //
        // We will also use r_product as our result array, even though it
        // yields asymptotically the same extra memory use, O(n)
        for (int i = 0; i < r_product.size(); i++) {
            r_product[i] *= l_product[i];
        }

        return r_product;
    }
};
