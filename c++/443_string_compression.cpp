class Solution {
private:
    // Writes compressed numbers to chars, returns updated total compressed length
    int write_num(vector<char>& chars, char c, int num, int ind) {
        chars[ind] = c;
        ind++;

        if (num > 1) {
            auto str_num = std::to_string(num);
            for (char n : str_num) {
                chars[ind] = n;
                ind++;
            }
        }

        return ind;
    }
public:
    int compress(vector<char>& chars) {
        int len_count = 0;
        char cur_char = chars[0];
        int cur_char_count = 0;

        for (char c : chars) {
            if (c == cur_char) {
                cur_char_count++;
            } else {
                len_count = write_num(chars, cur_char, cur_char_count, len_count);
                cur_char = c;
                cur_char_count = 1;
            }
        }

        len_count = write_num(chars, cur_char, cur_char_count, len_count);
        return len_count;
    }
};

