#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int n) {
        vector<int> v = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;

        for (int i = 0; i < v.size(); ++i) {
            while (n >= v[i]) {
                res += s[i];
                n -= v[i];
            }
        }

        return res;
    }
};
