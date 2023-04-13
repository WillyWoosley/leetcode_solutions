class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int cur_push = 0, cur_pop = 0, cur_stack = -1;
        
        // Essentially do mock run of stack push and pop operations, using
        // 'pushed' array as in place pseudo-stack
        while (cur_pop < popped.size()) {
            // If next expected element is on top of stack, 'pop' it
            if (cur_stack >= 0 && pushed[cur_stack] == popped[cur_pop]) {
                cur_stack -= 1;
                cur_pop += 1;
            } else { // Otherwise, 'push' the next element onto the 'stack'
                // If run off the back of pushed looking for it, sequence invalid
                if (cur_push == pushed.size()) {
                    return false;
                }
                
                cur_stack += 1;
                pushed[cur_stack] = pushed[cur_push];
                cur_push += 1;
            }
        }

        // If got through whole of popped array, sequence is valid
        return true;
    }
};
