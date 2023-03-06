class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;

        for (char c : s) {
            switch (c) {
                case ')':
                    if (stack.empty() || stack.back() != '(') {
                        return false;
                    } else {
                        stack.pop_back();
                    }
                    break;
                case ']':
                    if (stack.empty() || stack.back() != '[') {
                        return false;
                    } else {
                        stack.pop_back();
                    }
                    break;
                case '}':
                    if (stack.empty() || stack.back() != '{') {
                        return false;
                    } else {
                        stack.pop_back();
                    }
                    break;
                default:
                    stack.push_back(c);
            }
        }

        return stack.empty();
    }
};
