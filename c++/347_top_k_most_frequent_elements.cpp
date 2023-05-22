class Solution {
private:
    vector<int> unique;
    unordered_map<int, int> num_freq;

    int partition(int l, int r, int pivot_index) {
        swap(unique[pivot_index], unique[r]); // Place pivot at end
        int pivot = num_freq[unique[r]], replace = l;

        // Move all elements less frequent than pivot to the left
        for (int i = l; i < r; i++) {
            if (num_freq[unique[i]] < pivot) {
                swap(unique[i], unique[replace]);
                replace += 1;
            }
        }

        // Put the pivot on the boundary between less and more frequent elements,
        // and return that boundary position
        swap(unique[replace], unique[r]);
        return replace;

    }

    void quickselect(int l, int r, int boundary) {
        if (l == r) {
            return;
        }

        // Pick middle and partition there
        int pivot_final = partition(l, r, (l + r) / 2);

        if (pivot_final == boundary) { // Pivot element slots onto boundary
            return;                    // between last k elements and rest
        } else if (boundary < pivot_final) { // Order more on the left
            quickselect(l, pivot_final - 1, boundary);
        } else { // Order more on the right
            quickselect(pivot_final + 1, r, boundary);
        }
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create hashmap of numbers-># of occurences
        for (int n : nums) {
            num_freq[n] += 1;
        }

        // Create vector of all unique numbers in nums
        for (auto freq : num_freq) {
            unique.push_back(freq.first);
        }

        // Run quickselect on unique array by frequency and return lask k elements
        quickselect(0, unique.size() - 1, unique.size() - k);
        return vector<int>(unique.end() - k, unique.end());
        
    }
};
