class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>();
        }

        string keys[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Calculate total number of combos
        int res_count = 1;
        for (auto digit : digits) {
            res_count *= keys[digit - '0'].length();
        }
        vector<string> res(res_count, "");

        // Iteratively construct combos
        int rep_count = res_count;
        for (auto digit : digits) {
            string* key_chars = &keys[digit - '0'];
            rep_count /= key_chars->length();
            int key_index = -1;
            char app_char;

            for (int i = 0; i < res_count; i++) {
                if (i % rep_count == 0) {
                    key_index = (key_index + 1) % key_chars->length();
                    app_char = key_chars->at(key_index); 
                }

                res[i] += app_char;
            }
        }

        return res;
    }
};

