class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tgt) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int s = nums[l] + nums[r];
            if (s == tgt) {
                return {l + 1, r + 1};
            } else if (s < tgt) {
                ++l;
            } else {
                --r;
            }
        }
        
        return {};
    }
};
