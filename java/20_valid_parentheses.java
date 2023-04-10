class Solution {
    public boolean isValid(String s) {
        Stack<Character> parens = new Stack();

        for (int i = 0; i < s.length(); i++) {
            char cur_char = s.charAt(i);
            switch (cur_char) {
                case '(':
                    parens.push(cur_char);
                    break;
                case '[':
                    parens.push(cur_char);
                    break;
                case '{':
                    parens.push(cur_char);
                    break;
                case ')':
                    if (parens.empty() || parens.pop() != '(') {
                        return false;
                    }    
                    break;
                case ']':
                    if (parens.empty() || parens.pop() != '[') {
                        return false;
                    }    
                    break;
                case '}':
                    if (parens.empty() || parens.pop() != '{') {
                        return false;
                    }    
                    break;
                default:
                    return false;
            }
        }

        return parens.empty();
    }
}
