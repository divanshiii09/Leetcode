class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        int totalProduct = 1;
        int zeroCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
            } else {
                totalProduct *= nums[i];
            }
        }
        
        if (zeroCount > 1) {
            return answer;  
        }
        
        if (zeroCount == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    answer[i] = totalProduct;
                } else {
                    answer[i] = 0;  
                }
            }
        } else {   
            for (int i = 0; i < n; i++) {
                answer[i] = totalProduct / nums[i];
            }
        }
        
        return answer;
    }
};
