class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int leftMax1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int rightMin1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int leftMax2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int rightMin2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                if ((m + n) % 2 == 0) {
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
                } else {
                    return max(leftMax1, leftMax2);
                }
            } else if (leftMax1 > rightMin2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted.");
    }
};
