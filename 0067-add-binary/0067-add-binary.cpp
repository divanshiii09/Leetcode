class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result = "";
        while (i >= 0 || j >= 0 || carry) {
            int bit_a = (i >= 0) ? a[i] - '0' : 0;
            int bit_b = (j >= 0) ? b[j] - '0' : 0;
            int sum = bit_a + bit_b + carry;
            carry = sum / 2;
            result = char((sum % 2) + '0') + result;
            i--;
            j--;
        }
        return result;
    }
};
