class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> r(min(numRows, int(s.size())));
        int row = 0;
        bool down = false;

        for (char c : s) {
            r[row] += c;
            if (row == 0 || row == numRows - 1) down = !down;
            row += down ? 1 : -1;
        }

        string res;
        for (string x : r) res += x;
        return res;
    }
};
