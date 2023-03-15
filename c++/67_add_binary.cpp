class Solution {
private:
    string addBinaryHelper(string& a, string& b, int carry, ostringstream& acc) {
        int a_bit = 0, b_bit = 0;
        bool done = true;
        if (a.length() > 0) {
            a_bit = a.back() == '0' ? 0 : 1;
            a.pop_back();
            done = false;
        }
        if (b.length() > 0) {
            b_bit = b.back() == '0' ? 0 : 1;
            b.pop_back();
            done = false;
        }
        
        if (done && carry == 0) {
            return acc.str();
        }

        int sum = a_bit + b_bit + carry;
        switch (sum) {
            case 0:
                acc << '0';
                break;
            case 1:
                acc << '1';
                carry = 0;
                break;
            case 2:
                acc << '0';
                carry = 1;
                break;
            case 3:
                acc << '1';
                carry = 1;
                break;
        }
        
        return addBinaryHelper(a, b, carry, acc);
    }
public:
    string addBinary(string a, string b) {
        ostringstream res;
        string added = addBinaryHelper(a, b, 0, res);
        reverse(added.begin(), added.end());
        return added;
    }
};
