#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ints) {
        sort(ints.begin(), ints.end());
        
        vector<vector<int>> res;
        
        for (const auto& i : ints) {
            if (res.empty() || res.back()[1] < i[0]) {
                res.push_back(i);
            } else {
                res.back()[1] = max(res.back()[1], i[1]);
            }
        }
        
        return res;
    }
};
