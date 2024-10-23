class Solution {
public:
    void mergeSort(vector<pair<int, int>>& arr, vector<int>& counts, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(arr, counts, left, mid);
        mergeSort(arr, counts, mid + 1, right);
        merge(arr, counts, left, mid, right);
    }
    
    void merge(vector<pair<int, int>>& arr, vector<int>& counts, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;
        
        while (i <= mid && j <= right) {
            if (arr[i].first <= arr[j].first) {
                counts[arr[i].second] += rightCount;
                temp[k++] = arr[i++];
            } else {
                rightCount++;
                temp[k++] = arr[j++];
            }
        }
        
        while (i <= mid) {
            counts[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        }
        
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        for (int i = left; i <= right; i++) {
            arr[i] = temp[i - left];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> arr(n);
        
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        
        mergeSort(arr, counts, 0, n - 1);
        
        return counts;
    }
};
