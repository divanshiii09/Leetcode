class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        
        if (i >= s.length()) return 0;
        
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        long result = 0;
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }
        
        return static_cast<int>(result * sign);
    }
};
