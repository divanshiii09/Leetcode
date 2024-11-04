class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string combination;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(combination);
                return;
            }

            string chars = mapping[digits[index] - '0'];
            for (char c : chars) {
                combination.push_back(c);
                backtrack(index + 1);
                combination.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};
