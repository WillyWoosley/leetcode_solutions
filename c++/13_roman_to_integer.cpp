class Solution {
public:
    int romanToInt(string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'I':
                    if (i < s.length() - 1 && (s[i+1] == 'V' || s[i+1] == 'X')) {
                        count -= 1;
                    } else {
                        count += 1;
                    }
                    break;
                case 'V':
                    count += 5;
                    break;
                case 'X':
                    if (i < s.length() - 1 && (s[i+1] == 'L' || s[i+1] == 'C')) {
                        count -= 10;
                    } else {
                        count += 10;
                    }
                    break;
                case 'L':
                    count += 50;
                    break;
                case 'C':
                    if (i < s.length() - 1 && (s[i+1] == 'D' || s[i+1] == 'M')) {
                        count -= 100;
                    } else {
                        count += 100;
                    }
                    break;
                case 'D':
                    count += 500;
                    break;
                case 'M':
                    count += 1000;
                    break;
            }
        }

        return count;
    }
};

