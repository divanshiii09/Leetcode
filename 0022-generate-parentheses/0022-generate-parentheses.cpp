class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
    
private:
    void generate(vector<string>& res, string str, int open, int close, int n) {
        if (str.length() == n * 2) {
            res.push_back(str);
            return;
        }
        if (open < n) generate(res, str + "(", open + 1, close, n);
        if (close < open) generate(res, str + ")", open, close + 1, n);
    }
};
