#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        int l = m[0][0], r = m[n - 1][n - 1];
        
        auto countLE = [&](int mid) {
            int cnt = 0, j = n - 1;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && m[i][j] > mid) {
                    --j;
                }
                cnt += (j + 1);
            }
            return cnt;
        };
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (countLE(mid) < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return l;
    }
};
