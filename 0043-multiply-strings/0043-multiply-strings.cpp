class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i + j] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
        
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        
        string product;
        for (int i = res.size() - 1; i >= 0; --i) product += (res[i] + '0');
        
        return product;
    }
};
