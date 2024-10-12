class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        if (nums[s] < nums[e]) {
            return nums[s];
        }
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (mid < e && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            
            if (mid > s && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            
            if (nums[mid] >= nums[s]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        return nums[0];
    }
};
