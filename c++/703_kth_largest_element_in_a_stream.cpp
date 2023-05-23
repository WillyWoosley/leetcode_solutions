class KthLargest {
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> k_largest;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;

        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        k_largest.push(val);
        while (k_largest.size() > size) {
            k_largest.pop();
        }
        return k_largest.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
