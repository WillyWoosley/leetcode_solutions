class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> token_stack;

        for (string s : tokens) {
            if ((s[0] >= '0' && s[0] <= '9') || s.length() > 1) {
                token_stack.push(stoi(s));
            } else {
                int r = token_stack.top();
                token_stack.pop();
                int l = token_stack.top();
                token_stack.pop();
                
                switch(s[0]) {
                    case '+':
                        token_stack.push(l + r);
                        break;
                    case '-':
                        token_stack.push(l - r);
                        break;
                    case '*':
                        token_stack.push(l * r);
                        break;
                    case '/':
                        token_stack.push(l / r);
                        break;
                }
            }
        }

        return token_stack.top();
    }
};
