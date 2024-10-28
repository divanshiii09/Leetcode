#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        
        auto countLessEqual = [&](int mid) {
            int count = 0, j = n - 1;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) {
                    --j;
                }
                count += (j + 1);
            }
            return count;
        };
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
